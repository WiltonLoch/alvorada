#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <memory>
#include <utility>

#include <boost/serialization/vector.hpp>

#include <Transaction.hpp>
#include <BlockHeader.hpp>

class Block{
	private:
		unsigned int block_size;
		std::shared_ptr<BlockHeader> header;
		std::vector<int> tx_type;
		std::vector<std::shared_ptr<Transaction>> transactions;

		friend class boost::serialization::access;
		template <class Archive> void serialize(Archive & ar, unsigned int version){
			ar & this->block_size;
			if(header == nullptr) header = new BlockHeader();
			ar & header;
			if(transactions.size() == 0){
				unsigned int tx_amount;
				ar & tx_amount;
				for(int i = 0; i < tx_amount; i++){
				}
			}
			/* ar & tx_amount; */
			/* ar & serviceRequests; */
			/* ar & serviceProposals; */
		}
	public:
		Block();
		~Block();

		void setBlockSize(unsigned int version);
		unsigned int getBlockSize();

		std::shared_ptr<BlockHeader> getBlockHeader();

		void addTX(std::shared_ptr<Transaction> tx);
		
		unsigned char* createMerkleTree();
};


#endif
