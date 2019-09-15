#include <queue>
#include <cstring>
#include <bitset>
#include <iostream>
#include <csignal>

#include <openssl/sha.h>

#include <ServiceRequest.hpp>
#include <ServiceProposal.hpp>
#include <BlockHeader.hpp>
#include <Block.hpp>
#include <config.hpp>

Block::Block(){
	header = new header();
}

Block::~Block(){}

unsigned int Block::getBlockSize(){
	return block_size;
}

std::shared_ptr<BlockHeader> Block::getBlockHeader(){
	return header;
}

void Block::addTX(std::shared_ptr<ServiceRequest> tx){
	in_order.push_back(std::make_pair(SERVICE_REQUEST, serviceRequests.size()));
	serviceRequests.push_back(tx);
}

void Block::addTX(std::shared_ptr<ServiceProposal> tx){
	in_order.push_back(std::make_pair(SERVICE_PROPOSAL, serviceRequests.size()));
	serviceProposals.push_back(tx);
}

unsigned char* Block::createMerkleTree(){
	std::queue<unsigned char*> hashQueue;
	if(in_order.size() == 0) return nullptr;

	for(int i = 0; i < in_order.size(); i++){
		switch(in_order[i].first){
			case SERVICE_REQUEST:
				hashQueue.push(serviceRequests[in_order[i].second]->getHash());	
				/* printf("hash1: %s\n", serviceRequests[in_order[i].second]->getHexHash()); */	
				break;
			case SERVICE_PROPOSAL:
				hashQueue.push(serviceProposals[in_order[i].second]->getHash());	
				/* printf("hash2: %s\n", serviceProposals[in_order[i].second]->getHexHash()); */	
				break;
		}	
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

{
	header->
}
	
