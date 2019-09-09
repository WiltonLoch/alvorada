#ifndef COMMOM_VERIFICATOR_H
#define COMMON_VERIFICATOR_H

#include<Transaction.hpp>

namespace verification{
	
	bool verifyServiceProposal(std::shared_ptr<ServiceProposal> tx);

}


#endif
