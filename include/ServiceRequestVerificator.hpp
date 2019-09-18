#ifndef SERVICE_REQUEST_VERIFICATOR_H
#define SERVICE_REQUEST_VERIFICATOR_H

#include<ServiceRequest.hpp>

namespace verification{
	
	bool verifyServiceRequest(std::shared_ptr<ServiceRequest> tx);

}


#endif
