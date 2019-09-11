#include <BlockHeader.hpp>

BlockHeader::BlockHeader(unsigned int version, unsigned char* previous_block_hash, unsigned char* merkle_root) : version(version), previous_block_hash(previous_block_hash), merkle_root(merkle_root){}

BlockHeader::~BlockHeader(){
	delete [] previous_block_hash;
	delete [] merkle_root;
}

void BlockHeader::setVersion(unsigned int version){
	this->version = version;
}

unsigned int BlockHeader::getVersion(){
	return version;
}

void BlockHeader::setPreviousBlockHash(unsigned char* previous_block_hash){
	this->previous_block_hash = previous_block_hash;
}

unsigned char* BlockHeader::getPreviousBlockHash(){
	return previous_block_hash;
}

void BlockHeader::setMerkleRoot(unsigned char* merkle_root){
	this->merkle_root = merkle_root;
}

unsigned char* BlockHeader::getMerkleRoot(){
	return merkle_root;
}
