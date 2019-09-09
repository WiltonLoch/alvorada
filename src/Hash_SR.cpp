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
#include <VerifySRSig.hpp>

namespace hash{

	bool hashServiceRequest(std::shared_ptr<ServiceRequest> tx){
		std::stringstream serialized_string;
		{
			boost::archive::binary_oarchive out_archive(serialized_string);
			out_archive << *tx;
		}
			
	}

}

#endif
