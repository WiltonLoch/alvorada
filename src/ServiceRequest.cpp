#include <cstring>
#include <fstream>
#include <memory>

#include <openssl/sha.h>

#include <config.hpp>
#include <ServiceRequest.hpp>

ServiceRequest::ServiceRequest(){};

ServiceRequest::ServiceRequest(unsigned int version, char *address, unsigned char lock_model, std::string filename) : Transaction(version, address, SERVICE_REQUEST){
	this->lock_model = lock_model;
	std::unique_ptr<GraphFacade> graphFacade (new GraphFacade());
	data = graphFacade->generateRawData(data_size, filename);
}

ServiceRequest::~ServiceRequest(){
	delete[] data;
}

void ServiceRequest::setLockModel(unsigned char lockmodel){
	this->lock_model = lockmodel;
}

unsigned char* ServiceRequest::getGraphData(){
	return data;
}
