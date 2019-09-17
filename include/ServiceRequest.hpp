#ifndef SERVICE_REQUEST_H
#define SERVICE_REQUEST_H

#include <Transaction.hpp>
#include <GraphFacade.hpp>

class ServiceRequest : public Transaction{
    	private:
		friend class boost::serialization::access;
		template <class Archive> void serialize(Archive & ar, unsigned int version){
			ar & boost::serialization::base_object<Transaction>(*this);
			ar & lock_model;
			/* printf("lock_model: %d\n", lock_model); */
			ar & data_size;
			/* printf("data_size: %d\n", data_size); */
			if(data == nullptr) data = new unsigned char[data_size];
			for(unsigned int i = 0; i < data_size; i++)ar & data[i];
		}

		unsigned char lock_model;
		unsigned int data_size;
		unsigned char *data;
    	public:
		ServiceRequest();
		ServiceRequest(unsigned int version, char *address, unsigned char lock_model, std::string filename);
		~ServiceRequest();
		/* ServiceRequest(unsigned char* raw_tx); */

		void setLockModel(unsigned char lockmodel);
		unsigned char* getGraphData();
};

#endif
