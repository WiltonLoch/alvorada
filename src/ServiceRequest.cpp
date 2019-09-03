#include <cstring>
#include <ServiceRequest.hpp>


ServiceRequest::ServiceRequest(unsigned int version, unsigned char *address, unsigned char tx_type, unsigned char lock_model, std::string filename) :
Transaction(version, address, tx_type){
	this->lock_model = lock_model;
	GraphFacade* graphFacade = new GraphFacade();
	data = graphFacade->generateRawData(data_size, filename);
}

ServiceRequest::ServiceRequest(unsigned char* raw_tx) : Transaction(raw_tx){
	unsigned int offset = 0;
	memcpy(&lock_model, raw_tx, sizeof(unsigned char));
	offset += sizeof(unsigned char);
	memcpy(data_hash, raw_tx + offset, 32);
	offset += 32;
	memcpy(&data_size, raw_tx + offset, sizeof(unsigned int));
	offset += sizeof(unsigned int);
	memcpy(data, raw_tx + offset, data_size);
}

unsigned char* ServiceRequest::exportRawData(){
	unsigned int start_offset;
	unsigned char* commonData = generateRawCommonData(start_offset);
	int raw_data_size = start_offset + 34 + data_size; //total size is given by 35 from commom data, 1 from lock_model, 32 from data_hash, 1 from data_size, data_size from data. 
	unsigned char* raw_tx = new unsigned char[raw_data_size];
	memcpy(raw_tx, commonData, start_offset);
	delete[] commonData;
	memcpy(raw_tx + start_offset, &lock_model, sizeof(unsigned char));
	start_offset += sizeof(unsigned char);
	memcpy(raw_tx + start_offset, data_hash, 32);
	start_offset += 32;
	memcpy(raw_tx + start_offset, &data_size, sizeof(unsigned int));
	start_offset += sizeof(unsigned int);
	memcpy(raw_tx + start_offset, data, data_size);

	return raw_tx;
}

unsigned int ServiceRequest::getVersion(){
	return 0;
}
