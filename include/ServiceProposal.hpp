#ifndef SERVICE_PROPOSAL_H
#define SERVICE_PROPOSAL_H

#include <boost/serialization/vector.hpp>

#include <Transaction.hpp>
#include <GraphFacade.hpp>

class ServiceProposal : public Transaction{
    	private:
		friend class boost::serialization::access;
		template <class Archive> void serialize(Archive & ar, unsigned int version){
			ar & boost::serialization::base_object<Transaction>(*this);
			if(serviceRequestHash == nullptr) serviceRequestHash = new unsigned char[32];
			for(unsigned int i = 0; i < 32; i++)ar & serviceRequestHash[i];
			ar & suppliedNodeAmount;
			ar & suppliedNodes;
			ar & pricePolicy;
			ar & price;

		}
		unsigned char* serviceRequestHash;
		unsigned int suppliedNodeAmount;
		std::vector<unsigned int> suppliedNodes;
		unsigned int pricePolicy;
		float price;

    	public:
		ServiceProposal();
		ServiceProposal(unsigned int version, char *address, unsigned char lock_model, std::string filename);
		~ServiceProposal();
		/* ServiceProposal(unsigned char* raw_tx); */
};

#endif
