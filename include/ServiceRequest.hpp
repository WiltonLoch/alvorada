#ifndef SERVICE_REQUEST_H
#define SERVICE_REQUEST_H

#include <Transaction.hpp>
#include <GraphFacade.hpp>

class ServiceRequest : public Transaction{
    private:
	friend class boost::serialization::access;
        unsigned char lock_model;
        unsigned char data_hash[32];
        unsigned int data_size;
        unsigned char *data;
    public:
        ServiceRequest(unsigned int version, char *address, unsigned char tx_type, unsigned char lock_model, std::string filename);
	~ServiceRequest();
        /* ServiceRequest(unsigned char* raw_tx); */

	template <class Archive> void serialize(Archive & ar, unsigned int version){
		ar & boost::serialization::base_object<Transaction>(*this);
		ar & lock_model;
		for(int i = 0; i < 32; i++)ar & data_hash[i];
		ar & data_size;
		for(unsigned int i = 0; i < data_size; i++)ar & data[i];
	}

	void generateDataHash();
	void setLockModel(unsigned char lockmodel);
};

#endif
