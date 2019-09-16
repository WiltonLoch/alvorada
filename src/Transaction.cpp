#include <boost/iostreams/stream.hpp>
#include <boost/iostreams/device/back_inserter.hpp>
#include <openssl/bn.h>

#include <Transaction.hpp>

Transaction::Transaction(){}

Transaction::Transaction(unsigned int version, char *address)  : version(version), address(address){}

Transaction::~Transaction(){
	delete[] tx_hash;
	delete[] address;
	delete[] signature;
}

void Transaction::removeSignatureSerialization(){
	remove_signature_serialization = true;
}

void Transaction::addSignatureSerialization(){
	remove_signature_serialization = false;
}

void Transaction::removeHashSerialization(){
	remove_hash_serialization = true;
}

void Transaction::addHashSerialization(){
	remove_hash_serialization = false;
}

void Transaction::setSignature(unsigned char *signature){
	this->signature = signature;
}

unsigned char* Transaction::getSignature(){
	return signature;
}

void Transaction::setSignatureSize(unsigned char signature_size){
	this->signature_size = signature_size;
}

unsigned char Transaction::getSignatureSize(){
	return signature_size;
}

void Transaction::setAddress(char* address){
	this->address = address;
}

char* Transaction::getAddress(){
	return address;
}

void Transaction::setVersion(unsigned int version){
	this->version = version;
}

unsigned int Transaction::getVersion(){
	return version;
}

char* Transaction::getHexHash(){
	BIGNUM *tmp_hash_val = BN_new();
	BN_bin2bn(const_cast<const unsigned char *>(tx_hash), 32, tmp_hash_val);
	return BN_bn2hex(tmp_hash_val);
}

unsigned char* Transaction::getHash(){
	return tx_hash;
}

void Transaction::setHash(unsigned char* tx_hash){
	this->tx_hash = tx_hash;
}
