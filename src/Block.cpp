#include <queue>
#include <cstring>
#include <bitset>
#include <iostream>

#include <openssl/sha.h>

#include <ServiceRequest.hpp>
#include <ServiceProposal.hpp>
#include <BlockHeader.hpp>
#include <Block.hpp>
#include <config.hpp>

Block::Block(){}
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
	/* bool already_padded = true; */
	/* if((in_order.size() % 2) == 1) already_padded = false; */

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
		/* if(i == in_order.size() - 1 and !already_padded){ */
		       	/* i--; */
			/* already_padded = true; */
		/* } */
	}		

	unsigned char* tmpHash = new unsigned char[64];
	unsigned int removed_nodes = 0;
	printf("in size: %d\n", hashQueue.size());
	while(hashQueue.size() != 1){
		printf("rn: %d\n", hashQueue.size());
		/* memcpy(tmpHash, hashQueue.front(), 32); */
		if(removed_nodes >= in_order.size()) delete [] hashQueue.front();
		hashQueue.pop();
		removed_nodes++;
		/* memcpy(tmpHash + 32, hashQueue.front(), 32); */
		if(removed_nodes >= in_order.size()) delete [] hashQueue.front();
		hashQueue.pop();
		removed_nodes++;
		unsigned char* resultingHash = new unsigned char[32];
		SHA256(tmpHash, 64, resultingHash);
		hashQueue.push(SHA256(resultingHash, 32, resultingHash));
	}
	printf("abacate\n");
	delete [] tmpHash;
	return hashQueue.front();
	/* return nullptr; */
	
}


