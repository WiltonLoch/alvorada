#ifndef UTILS_SIGN_H
#define UTILS_SIGN_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <bitset>
#include <memory>

#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/export.hpp>

#include <Key.hpp>
#include <ServiceRequest.hpp>
#include <Sign_SR.hpp>

namespace signature{

	void signServiceRequest(std::shared_ptr<Key> key, std::shared_ptr<ServiceRequest> tx){
		tx->removeSignatureSerialization();
		std::stringstream serialized_string;	
		{
			boost::archive::binary_oarchive out_archive(serialized_string);

			out_archive << *tx;
		}
		unsigned char size;
		tx->setSignature(key->sign(reinterpret_cast<unsigned char*>(const_cast<char *>(serialized_string.str().c_str())), serialized_string.str().length(), size));
		tx->setSignatureSize(size);

		tx->addSignatureSerialization();
	}

};
#endif
