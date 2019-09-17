#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <memory>
#include <utility>

#include <boost/serialization/vector.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/split_member.hpp>

#include <config.hpp>
#include <Transaction.hpp>
#include <ServiceRequest.hpp>
#include <ServiceProposal.hpp>
#include <BlockHeader.hpp>

class Block{
	private:
		unsigned int block_size;
		std::shared_ptr<BlockHeader> header;
		std::vector<unsigned int> tx_types;
		std::vector<std::shared_ptr<Transaction>> transactions;

		friend class boost::serialization::access;

		template <class Archive> void save(Archive & ar, unsigned int version) const {
			ar & block_size;
			ar & *header;
			ar & static_cast<unsigned int>(transactions.size());
			for(int i = 0; i < transactions.size(); i++){
				ar & tx_types[i];
				/* printf("type_s: %d\n", tx_types[i]); */

				switch(tx_types[i]){
					case SERVICE_REQUEST:
						ar & *std::dynamic_pointer_cast<ServiceRequest>(transactions[i]);
						break;
					case SERVICE_PROPOSAL:
						ar & *(std::dynamic_pointer_cast<ServiceProposal>(transactions[i]));
						break;
				}	

			}
		}

		template <class Archive> void load(Archive & ar, unsigned int version){
			ar & block_size;
			if(header == nullptr) header = std::make_shared<BlockHeader>();
			ar & *header;
			unsigned int tx_amount, tx_type;
			ar & tx_amount;
			for(int i = 0; i < tx_amount; i++){
				ar & tx_type;
				switch(tx_type){
					case SERVICE_REQUEST:{
						std::shared_ptr<ServiceRequest> tmpSR (new ServiceRequest());
						ar & *tmpSR;
						this->addTx(tmpSR);
						break;
					}
					case SERVICE_PROPOSAL:{
						std::shared_ptr<ServiceProposal> tmpSP (new ServiceProposal());
						ar & *tmpSP;
						this->addTx(tmpSP);
						break;
					}
				}	
			}
		}

		BOOST_SERIALIZATION_SPLIT_MEMBER()
	public:
		Block();
		~Block();

		void setBlockSize(unsigned int size);
		unsigned int getBlockSize();

		void removeHashSerialization();
		void addHashSerialization();

		char* getHexHash();
		unsigned char* getHash();
		void setHash(unsigned char* tx_hash);

		std::shared_ptr<BlockHeader> getBlockHeader();

		void addTx(std::shared_ptr<Transaction> tx);
		bool store();
		
		unsigned char* createMerkleTree();
};


#endif
