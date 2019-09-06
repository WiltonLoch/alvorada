#ifndef COMMOM_VERIFICATOR_H
#define COMMON_VERIFICATOR_H

#include<Transaction.hpp>

namespace verification{
	
	bool verifyServiceRequest(std::shared_ptr<ServiceRequest> tx);

}


#endif
