#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <memory>
#include <utility>

#include <boost/serialization/vector.hpp>

#include <Transactions.hpp>
#include <BlockHeader.hpp>

class Block{
	private:
		unsigned int block_size;
		std::shared_ptr<BlockHeader> header;
		std::vector<Transaction> transactions;
		unsigned int tx_amount;

		friend class boost::serialization::access;
		template <class Archive> void serialize(Archive & ar, unsigned int version){
			ar & this->block_size;
			if(header == nullptr) header = new BlockHeader();
			ar & header;
			ar & tx_amount;
			ar & serviceRequests;
			ar & serviceProposals;
		}
	public:
		Block();
		~Block();

		void setBlockSize(unsigned int version);
		unsigned int getBlockSize();

		std::shared_ptr<BlockHeader> getBlockHeader();

		void addTX(std::shared_ptr<ServiceRequest> tx);
		void addTX(std::shared_ptr<ServiceProposal> tx);
		
		unsigned char* createMerkleTree();
};


#endif
