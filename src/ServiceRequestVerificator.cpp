#ifndef COMMOM_VERIFICATOR_H
#define COMMON_VERIFICATOR_H

#include <commomVerificator.hpp>
#include <Key.hpp>
#include <VerifySig.hpp>

namespace verification{
	
	bool verifyServiceRequest(std::shared_ptr<ServiceRequest> tx){
		verifyCommonData(tx);
		if(!signature::verifyServiceRequestSig(key, tx)) return false;
		return true;
	}

}


#endif
