#ifndef COMMOM_VERIFICATOR_H
#define COMMON_VERIFICATOR_H

#include <config.hpp>

#include <Key.hpp>
#include <ServiceProposal.hpp>
#include <VerifySig.hpp>

namespace verification{
	
	bool verifyServiceProposal(std::shared_ptr<ServiceProposal> tx){
		std::shared_ptr<Key> key (new Key(tx->getAddress()));
		if(tx->getVersion() != VERSION) return false;
		if(!signature::verifyTransactionSig(key, tx)) return false;

		/* std::unique_ptr<GraphFacade> graphFacade (new GraphFacade()); */
		/* if(!graphFacade->verifyGraph(tx->getGraphData())) return false; */
		return true;
	}

}


#endif
