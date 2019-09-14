#include <openssl/bn.h>
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

void BlockHeader::removeHashSerialization(){
	remove_hash_serialization = true;
}

void BlockHeader::addHashSerialization(){
	remove_hash_serialization = false;
}


void BlockHeader::setMerkleRoot(unsigned char* merkle_root){
	this->merkle_root = merkle_root;
}

unsigned char* BlockHeader::getMerkleRoot(){
	return merkle_root;
}

char* BlockHeader::getHexHash(){
	BIGNUM *tmp_hash_val = BN_new();
	BN_bin2bn(const_cast<const unsigned char *>(hash), 32, tmp_hash_val);
	return BN_bn2hex(tmp_hash_val);
}

unsigned char* BlockHeader::getHash(){
	return hash;
}

void BlockHeader::setHash(unsigned char* hash){
	this->hash = hash;
}
