#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <memory>
#include <utility>

#include <boost/serialization/vector.hpp>

#include <ServiceRequest.hpp>
#include <ServiceProposal.hpp>
#include <BlockHeader.hpp>

class Block{
	private:
		unsigned int block_size;
		std::shared_ptr<BlockHeader> header;
		std::vector<std::pair<int, int>> in_order;
		std::vector<std::shared_ptr<ServiceRequest>> serviceRequests;
		std::vector<std::shared_ptr<ServiceProposal>> serviceProposals;
		unsigned int tx_amount;

		friend class boost::serialization::access;
		template <class Archive> void serialize(Archive & ar, unsigned int version){
			unsigned int tx_amount = in_order.size();
			ar & this->block_size;
			if(header == nullptr) header = std::make_shared<BlockHeader>();
			ar & header;
			if(tx_amount == 0){
				ar & tx_amount;
				std::unique_ptr<Transaction> tmpTx (new Transaction());
				ar & tmpTx;
				switch(tmpTx->getTxType()){
					case 0:
						std::shared_ptr<ServiceRequest> tmpSR (tmpTx);
						serviceRequests.push_back(tmpSR);
						break;
					case 1:
						std::shared_ptr<ServiceProposal> tmpSP (tmpTx);
						serviceProposals.push_back(tmpSR);
						break;
				}

			}
			ar & serviceRequests;
			ar & serviceProposals;
		}
	public:
		Block();
		~Block();

		void setBlockSize(unsigned int size);
		unsigned int getBlockSize();

		std::shared_ptr<BlockHeader> getBlockHeader();

		void addTX(std::shared_ptr<ServiceRequest> tx);
		void addTX(std::shared_ptr<ServiceProposal> tx);
		
		unsigned char* createMerkleTree();
};


#endif
