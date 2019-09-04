#ifndef Transaction_H
#define Transaction_H
#include <string>
#include <fstream>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

class Transaction{
    protected:
	friend class boost::serialization::access;
        unsigned int version;
        unsigned char *tx_hash;
        char *address;
        unsigned char signature_size;
        unsigned char *signature;
        unsigned char tx_type;
	
	bool remove_signature_serialization = true;
    public:
        Transaction(unsigned int version, char *address, unsigned char tx_type);
        /* Transaction(unsigned char* raw_data); */
        virtual ~Transaction();

	template <class Archive> void serialize(Archive & ar, unsigned int version){
		ar & version;
		for(int i = 0; i < 20; i++)ar & address[i];
		ar & signature_size;
		if(!remove_signature_serialization) for(unsigned int i = 0; i < signature_size; i++)ar & signature[i];
		ar & tx_type;
	}
	void removeSignatureSerialization();
	void addSignatureSerialization();

        unsigned int getVersion();
        void setVersion(unsigned int version);

        unsigned char* getTxHash();
        void setTxHash(unsigned char* tx_hash);

        unsigned char* getAddress();
        void setAddress(unsigned char* address);

        unsigned char getSignatureSize();
        void setSignatureSize(unsigned char signature_size);

        unsigned char* getSignature();
        void setSignature(unsigned char *signature);

        unsigned char getTxType();
        void setTxType(unsigned char tx_type);

        
};

#endif
