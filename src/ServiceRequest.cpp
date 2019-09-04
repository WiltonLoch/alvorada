#include <cstring>
#include <fstream>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <ServiceRequest.hpp>
#include <boost/iostreams/device/back_inserter.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/serialization/base_object.hpp>
#include <openssl/sha.h>

ServiceRequest::ServiceRequest(unsigned int version, char *address, unsigned char tx_type, unsigned char lock_model, std::string filename) :
Transaction(version, address, tx_type){
	this->lock_model = lock_model;
	GraphFacade* graphFacade = new GraphFacade();
	data = graphFacade->generateRawData(data_size, filename);
	generateDataHash();
}

ServiceRequest::~ServiceRequest(){
	delete[] data;
}

void ServiceRequest::generateDataHash(){
	SHA256(data, data_size, data_hash);	
}
