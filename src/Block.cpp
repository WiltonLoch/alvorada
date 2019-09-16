#include <queue>
#include <cstring>
#include <bitset>
#include <iostream>
#include <csignal>
#include <memory>

#include <openssl/sha.h>

#include <ServiceRequest.hpp>
#include <ServiceProposal.hpp>
#include <BlockHeader.hpp>
#include <Block.hpp>
#include <config.hpp>

Block::Block(){
	header = std::make_shared<BlockHeader>(); 
}

Block::~Block(){}

unsigned int Block::getBlockSize(){
	return block_size;
}

std::shared_ptr<BlockHeader> Block::getBlockHeader(){
	return header;
}

void Block::addTX(std::shared_ptr<Transaction> tx){
	transactions.push_back(tx);
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
