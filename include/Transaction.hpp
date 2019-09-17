#ifndef Transaction_H
#define Transaction_H
#include <string>
#include <fstream>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

class Transaction{
	private:
		friend class boost::serialization::access;
		template <class Archive> void serialize(Archive & ar, unsigned int version){
			ar & tx_version;
			if(!remove_hash_serialization){
				if(tx_hash == nullptr) tx_hash = new unsigned char[32];
				for(int i = 0; i < 32; i++) ar & tx_hash[i];
			}
			if(address == nullptr){
				self_allocated_address = true;
			       	address = new char[66];
			}
			for(int i = 0; i < 66; i++) ar & address[i];
			if(!remove_signature_serialization){
				ar & signature_size;
				if(signature == nullptr) signature = new unsigned char[signature_size];
				for(unsigned int i = 0; i < signature_size; i++)ar & signature[i];
			}
			ar & tx_type;
		}
	protected:
		unsigned int tx_version;
		unsigned char *tx_hash = nullptr;
		char *address = nullptr;
		unsigned char signature_size;
		unsigned char *signature = nullptr;
		unsigned char tx_type;
		bool remove_signature_serialization = false;
		bool remove_hash_serialization = false;

		bool self_allocated_address = false;
    	public:
		Transaction();
		Transaction(unsigned int tx_version, char *address, unsigned char tx_type);
		/* Transaction(unsigned char* raw_data); */
		virtual ~Transaction();

		void removeHashSerialization();
		void addHashSerialization();

		void removeSignatureSerialization();
		void addSignatureSerialization();

		unsigned int getVersion();
		void setVersion(unsigned int version);

		char* getHexHash();
		unsigned char* getHash();
		void setHash(unsigned char* tx_hash);

		unsigned char getSignatureSize();
		void setSignatureSize(unsigned char signature_size);

		char* getAddress();
		void setAddress(char *address);

		unsigned char* getSignature();
		void setSignature(unsigned char *signature);

		unsigned char getTxType();
		void setTxType(unsigned char tx_type);
        
};

#endif
