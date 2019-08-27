#ifndef SERVICE_REQUEST_H
#define SERVICE_REQUEST_H

#include <Transaction.hpp>

class ServiceRequest : protected Transaction{
    private:
        unsigned char lock_model;
        unsigned char *data_hash;
        unsigned int data_size;
        unsigned char *data;
    public:
        ServiceRequest(unsigned char* raw_tx);

        unsigned char* exportRawData();
};

#endif