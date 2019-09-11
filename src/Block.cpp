#include <ServiceRequest.hpp>
#include <ServiceProposal.hpp>
#include <BlockHeader.hpp>
#include <Block.hpp>

Block::Block(){}
Block::~Block(){}

unsigned int Block::getBlockSize(){
	return block_size;
}

std::shared_ptr<BlockHeader> Block::getBlockHeader(){
	return header;
}

void Block::addTX(ServiceRequest tx){
	serviceRequests.push_back(tx);
	tx_amount++;
}

void Block::addTX(ServiceProposal tx){
	serviceProposals.push_back(tx);
	tx_amount++;
}


