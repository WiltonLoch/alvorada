#ifndef BLOCK_HEADER_H
#define BLOCK_HEADER_H

#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

class BlockHeader{
	private:
		unsigned int version;
		unsigned char* hash = nullptr;
		unsigned char* previous_block_hash = nullptr;
		unsigned char* merkle_root = nullptr;
		bool remove_hash_serialization = false; 
		friend class boost::serialization::access;

		template <class Archive> void serialize(Archive & ar, unsigned int version){
			ar & this->version;
			printf("v: %d\n", this->version);
			if(!remove_hash_serialization){
				if(hash == nullptr) hash = new unsigned char[32];
				for(int i = 0; i < 32; i++) ar & hash[i];
			}	
			if(previous_block_hash == nullptr) previous_block_hash = new unsigned char[32];
			for(int i = 0; i < 32; i++) ar & previous_block_hash[i];
			if(merkle_root == nullptr) merkle_root = new unsigned char[32];
			for(int i = 0; i < 32; i++) ar & merkle_root[i];
		
		}
	public:
		BlockHeader();
		BlockHeader(unsigned int version);
		BlockHeader(unsigned int version, unsigned char* previous_block_hash, unsigned char* merkle_root);
		~BlockHeader();

		void setVersion(unsigned int block_version);
		unsigned int getVersion();

		void setPreviousBlockHash(unsigned char* previous_block_hash);
		unsigned char* getPreviousBlockHash();

		void removeHashSerialization();
		void addHashSerialization();

		void setMerkleRoot(unsigned char* merkle_root);
		unsigned char* getMerkleRoot();

		char* getHexHash();
		unsigned char* getHash();
		void setHash(unsigned char* tx_hash);

};

#endif

