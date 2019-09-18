#ifndef COMMOM_VERIFICATOR_H
#define COMMON_VERIFICATOR_H

#include <config.hpp>

#include <Key.hpp>
#include <VerifySig.hpp>

namespace verification{
	
	bool verifyServiceRequest(std::shared_ptr<ServiceRequest> tx){
		std::shared_ptr<Key> key (new Key(tx->getAddress()));
		if(tx->getVersion() != VERSION) return false;
		if(!signature::verifySig(key, tx)) return false;

		std::unique_ptr<GraphFacade> graphFacade (new GraphFacade());
		if(!graphFacade->verifyGraph(tx->getGraphData())) return false;
		return true;
	}

}


#endif
