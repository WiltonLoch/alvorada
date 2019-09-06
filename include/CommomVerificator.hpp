#ifndef COMMOM_VERIFICATOR_H
#define COMMON_VERIFICATOR_H

#include<Transaction.hpp>

namespace verification{
	
	bool verifyCommonData(std::shared_ptr<Transaction> tx);

}


#endif
