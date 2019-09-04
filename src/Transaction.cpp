#include <Transaction.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/iostreams/device/back_inserter.hpp>

Transaction::Transaction(unsigned int version, char *address, unsigned char tx_type){
    this->version = version;
    this->address = address;
    this->tx_type = tx_type;
}

Transaction::~Transaction(){}

Transaction::removeSignatureSerialization(){
	removeSignatureSerialization = true;
}

Transaction::addSignatureSerialization(){
	removeSignatureSerialization = false;
}
