#ifndef BLOCK_HEADER_H
#define BLOCK_HEADER_H

#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

class BlockHeader{
	private:
		unsigned int version;
		unsigned char* previous_block_hash;
		unsigned char* merkle_root;
		friend class boost::serialization::access;

		template <class Archive> void serialize(Archive & ar, unsigned int version){
			ar & this->version;
			if(previous_block_hash == nullptr) previous_block_hash = new unsigned char[32];
			for(int i = 0; i < 32; i++) ar & previous_block_hash[i];
			if(merkle_root == nullptr) merkle_root = new unsigned char[32];
			for(int i = 0; i < 32; i++) ar & merkle_root[i];
		
		}
	public:
		BlockHeader();
		BlockHeader(unsigned int version, unsigned char* previous_block_hash, unsigned char* merkle_root);
		~BlockHeader();

		void setVersion(unsigned int version);
		unsigned int getVersion();

		void setPreviousBlockHash(unsigned char* previous_block_hash);
		unsigned char* getPreviousBlockHash();

		void setMerkleRoot(unsigned char* merkle_root);
		unsigned char* getMerkleRoot();
};

#endif
