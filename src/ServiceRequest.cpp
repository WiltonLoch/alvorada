#include <cstring>
#include <ServiceRequest.hpp>


ServiceRequest::ServiceRequest(unsigned int version, unsigned char *address, unsigned char tx_type, unsigned char lock_model, unsigned int data_size, unsigned char *data) :
Transaction(version, address, tx_type){
    this->lock_model = lock_model;
    this->data_size = data_size;
    this->data = data;
}

ServiceRequest::ServiceRequest(unsigned char* raw_tx) : Transaction(raw_tx){
    memcpy(&lock_model, raw_tx, 1);
    memcpy(data_hash, raw_tx, 32);
    memcpy(&data_size, raw_tx, 1);
    memcpy(data, raw_tx, data_size);
}

unsigned char* ServiceRequest::exportRawData(){
    int raw_data_size = 72 + data_size; //total size is given by 35 from commom data, 1 from lock_model, 32 from data_hash, 1 from data_size, data_size from data. 
    unsigned char* raw_tx = new unsigned char[raw_data_size];
    memcpy(raw_tx, generateRawCommomData(), 35);
    memcpy(raw_tx, &lock_model, 1);
    memcpy(raw_tx, data_hash, 32);
    memcpy(raw_tx, &data_size, 1);
    memcpy(raw_tx, data, data_size);

    return raw_tx;
}

bool ServiceRequest::verify(){
    return false;
}
