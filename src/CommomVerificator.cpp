#ifndef COMMOM_VERIFICATOR_H
#define COMMON_VERIFICATOR_H

#include <commomVerificator.hpp>
#include <Key.hpp>
#include <verifySig.hpp>

namespace verification{
	
	bool verifyCommonData(std::shared_ptr<Transaction> tx){
		if(tx->getVersion() != 1) return false;
		std::shared_ptr<Key> key (new Key(tx->getAddress()));
		if(!signature::verifyServiceRequestSig(key, tx)) return false;
		return true;
	}

}


#endif
