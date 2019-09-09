#ifndef COMMOM_VERIFICATOR_H
#define COMMON_VERIFICATOR_H

#include <Key.hpp>
#include <VerifySRSig.hpp>

namespace verification{
	
	bool verifyServiceRequest(std::shared_ptr<ServiceRequest> tx){
		printf("tx_addr: %s\n", tx->getAddress());
		std::shared_ptr<Key> key (new Key(tx->getAddress()));
		printf("tx_addr: %s\n", key->getAddress());
		if(!signature::verifyServiceRequestSig(key, tx)) return false;
		return true;
	}

}


#endif
