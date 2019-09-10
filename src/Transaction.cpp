#include <Transaction.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/iostreams/device/back_inserter.hpp>

Transaction::Transaction(){}

Transaction::Transaction(unsigned int version, char *address, unsigned char tx_type)  : version(version), address(address), tx_type(tx_type){}

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

unsigned char* Transaction::getHash(){
	return tx_hash;
}
void Transaction::setHash(unsigned char* tx_hash){
	this->tx_hash = tx_hash;
}
