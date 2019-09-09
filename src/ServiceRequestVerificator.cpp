#ifndef COMMOM_VERIFICATOR_H
#define COMMON_VERIFICATOR_H

#include <Key.hpp>
#include <VerifySRSig.hpp>

namespace verification{
	
	bool verifyServiceRequest(std::shared_ptr<ServiceRequest> tx){
		std::shared_ptr<Key>
		if(!signature::verifyServiceRequestSig(new Key(tx->getAddress), tx)) return false;
		return true;
	}

}


#endif
