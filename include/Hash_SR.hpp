#ifndef UTILS_VERIFY_SIG_H 
#define UTILS_VERIFY_SIG_H

#include <fstream>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/export.hpp>
#include <iostream>
#include <sstream>

#include <Key.hpp>
#include <Transaction.hpp>
#include <ServiceRequest.hpp>

namespace hash{

	void hashServiceRequest(std::shared_ptr<ServiceRequest> tx);

}

#endif