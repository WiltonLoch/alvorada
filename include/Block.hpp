#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <memory>

#include <boost/serialization/vector.hpp>

#include <ServiceRequest.hpp>
#include <ServiceProposal.hpp>
#include <BlockHeader.hpp>

class Block{
	private:
		unsigned int block_size;
		std::shared_ptr<BlockHeader> header;
		unsigned int tx_amount;
		std::vector<ServiceRequest> serviceRequests;
		std::vector<ServiceProposal> serviceProposals;

		friend class boost::serialization::access;
		template <class Archive> void serialize(Archive & ar, unsigned int version){
			ar & this->block_size;
			if(header == nullptr) header = new BlockHeader();
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

		void addTX(ServiceRequest tx);
		void addTX(ServiceProposal tx);
};


#endif
