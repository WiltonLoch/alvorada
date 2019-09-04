#ifndef UTILS_VERIFY_SIG_H 
#define UTILS_VERIFY_SIG_H

#include <fstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/export.hpp>
#include <iostream>
#include <sstream>

#include <Key.hpp>
#include <Transaction.hpp>
#include <ServiceRequest.hpp>

bool verifyTXSig(Key* key, ServiceRequest* tx){
	tx->removeSignatureSerialization();
	std::stringstream serialized_string;
	{
		boost::archive::text_oarchive out_archive(serialized_string);

		out_archive << *tx;
	}
	tx->addSignatureSerialization();

	return key->verify(reinterpret_cast<unsigned char*>(const_cast<char *>(serialized_string.str().c_str())), serialized_string.str().length(), tx->getSignature(), static_cast<unsigned int>(tx->getSignatureSize()));
}

#endif
