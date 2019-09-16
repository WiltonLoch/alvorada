#include <cstring>
#include <fstream>
#include <memory>

#include <openssl/sha.h>

#include <config.hpp>
#include <ServiceProposal.hpp>

ServiceProposal::ServiceProposal(){};

ServiceProposal::ServiceProposal(unsigned int version, char *address) : Transaction(version, address, SERVICE_PROPOSAL){
}

ServiceProposal::~ServiceProposal(){
	delete [] serviceRequestHash;
}
