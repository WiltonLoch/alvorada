#ifndef COMMOM_VERIFICATOR_H
#define COMMON_VERIFICATOR_H

#include <config.hpp>

#include <Key.hpp>
#include <VerifySRSig.hpp>

namespace verification{
	
	bool verifyServiceRequest(std::shared_ptr<ServiceRequest> tx){
		std::shared_ptr<Key> key (new Key(tx->getAddress()));
		if(tx->getVersion() != VERSION) return false;
		return signature::verifyServiceRequestSig(key, tx) 
		std::unique_ptr<GraphFacade> graphFacade (new GraphFacade());
		graphFacade->verifyGraph(tx->getGraphData());
		return true;
	}

}


#endif
