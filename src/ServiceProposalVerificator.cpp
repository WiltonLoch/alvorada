#include <config.hpp>

#include <Key.hpp>
#include <ServiceProposal.hpp>
#include <VerifySig.hpp>
#include <ServiceProposalVerificator.hpp>

namespace verification{
	
	bool verifyServiceProposal(std::shared_ptr<ServiceProposal> tx){
		std::shared_ptr<Key> key (new Key(tx->getAddress()));
		if(tx->getVersion() != VERSION) return false;
		if(!signature::verifySig(key, tx)) return false;

		/* std::unique_ptr<GraphFacade> graphFacade (new GraphFacade()); */
		/* if(!graphFacade->verifyGraph(tx->getGraphData())) return false; */
		return true;
	}

};
