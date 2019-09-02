#ifndef SERVICE_REQUEST_H
#define SERVICE_REQUEST_H

#include <Transaction.hpp>
#include <GraphFacade.hpp>

class ServiceRequest : public Transaction{
    private:
        unsigned char lock_model;
        unsigned char *data_hash;
        unsigned int data_size;
        unsigned char *data;
    public:
        ServiceRequest(unsigned int version, unsigned char *address, unsigned char tx_type, unsigned char lock_model, std::string filename);
        ServiceRequest(unsigned char* raw_tx);

        bool verify();

        unsigned char* exportRawData();
};

#endif
