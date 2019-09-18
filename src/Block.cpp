#include <queue>
#include <cstring>
#include <bitset>
#include <iostream>
#include <csignal>
#include <sstream>
#include <memory>
#include <unistd.h>

#include <openssl/sha.h>
#include <boost/filesystem.hpp>

#include <ServiceRequest.hpp>
#include <ServiceProposal.hpp>
#include <BlockHeader.hpp>
#include <Block.hpp>
#include <config.hpp>

#include <ServiceRequestVerificator.hpp>
#include <ServiceProposalVerificator.hpp>

Block::Block(){
	header = std::make_shared<BlockHeader>(1); 
}

Block::~Block(){}

unsigned int Block::getBlockSize(){
	return block_size;
}

std::shared_ptr<BlockHeader> Block::getBlockHeader(){
	return header;
}

void Block::addTx(std::shared_ptr<Transaction> tx){
	transactions.push_back(tx);
	tx_types.push_back(tx->getTxType());
}

void Block::setVersion(unsigned int block_version){
	header->setVersion(block_version);
}

unsigned int Block::getVersion(){
	return header->getVersion();
}


unsigned char* Block::createMerkleTree(){
	std::queue<unsigned char*> hashQueue;
	if(transactions.size() == 0) return nullptr;

	for(int i = 0; i < transactions.size(); i++){
		hashQueue.push(transactions[i]->getHash());	
	}		

	bool inner_nodes = false;
	unsigned char * tmpHash = new unsigned char[64];

	if(hashQueue.size() % 2 != 0) hashQueue.push(hashQueue.back());
	unsigned int previous_level_size = hashQueue.size();

	while(hashQueue.size() != 1){
		if(hashQueue.size() == previous_level_size/2){
		       	if(hashQueue.size() % 2 != 0) hashQueue.push(hashQueue.back());
			if(!inner_nodes) inner_nodes = true;
			previous_level_size = hashQueue.size();
		}
		memcpy(tmpHash, hashQueue.front(), 32);
		if(inner_nodes) delete [] hashQueue.front();
		hashQueue.pop();
		memcpy(tmpHash, hashQueue.front(), 32);
		/* if(inner_nodes) delete [] hashQueue.front(); */
		hashQueue.pop();

		unsigned char * resultingHash = new unsigned char[32];
		SHA256(tmpHash, 64, resultingHash);
		hashQueue.push(SHA256(resultingHash, 32, resultingHash));
	}

	return hashQueue.front();
	
} 

char* Block::getHexHash(){
	return header->getHexHash();
}

unsigned char* Block::getHash(){
	return header->getHash();
}

void Block::setHash(unsigned char* hash){
	header->setHash(hash);
}

void Block::removeHashSerialization(){
	header->removeHashSerialization();
}

void Block::addHashSerialization(){
	header->addHashSerialization();
}

bool Block::store(){
	std::stringstream dir_path; 
	dir_path << "blockchain/" << this->getHexHash();
	boost::filesystem::path block_dir(dir_path.str().c_str());	
	if(!boost::filesystem::create_directory(block_dir)) printf("Error creating block directory!\n");
	dir_path << "/";

	std::stringstream file_path;
	file_path << dir_path.str() << "header";
	std::ofstream exit_stream(file_path.str().c_str());
	{
		boost::archive::binary_oarchive out_archive(exit_stream);
		out_archive << *header;
	}

	std::stringstream symbolic_link, absolute_path;
	for(int i = 0; i < transactions.size(); i++){
		file_path.str("");
		symbolic_link.str("");
		absolute_path.str("");

		file_path << dir_path.str() << transactions[i]->getHexHash();
		symbolic_link << "utx/" << transactions[i]->getHexHash();
		absolute_path << boost::filesystem::current_path().native() << "/" << file_path.str();

		std::ofstream exit_stream(file_path.str().c_str());
		{
			boost::archive::binary_oarchive out_archive(exit_stream);
			switch(tx_types[i]){
				case SERVICE_REQUEST:
					out_archive << *std::dynamic_pointer_cast<ServiceRequest>(transactions[i]);
					if(symlink(absolute_path.str().c_str(), symbolic_link.str().c_str()) != 0) printf("Symlink creation failed!\n");
					break;
				case SERVICE_PROPOSAL:
					out_archive << *std::dynamic_pointer_cast<ServiceProposal>(transactions[i]);
					if(symlink(absolute_path.str().c_str(), symbolic_link.str().c_str()) != 0) printf("Symlink creation failed!\n");
					break;
			}	
		}
	}
	return true;
}

bool Block::verifyTransactions(){
	for(int i = 0; i < transactions.size(); i++){
		switch(tx_types[i]){
			case SERVICE_REQUEST:
				if(!verification::verifyServiceRequest(std::dynamic_pointer_cast<ServiceRequest>(transactions[i]))) return false;

				break;
			case SERVICE_PROPOSAL:
				if(!verification::verifyServiceProposal(std::dynamic_pointer_cast<ServiceProposal>(transactions[i]))) return false;
				break;
		}	
	}
	return true;
}
