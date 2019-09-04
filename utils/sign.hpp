#ifndef UTILS_SIGN_H
#define UTILS_SIGN_H

#include <fstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/export.hpp>
#include <iostream>
#include <sstream>
#include <bitset>

#include <Key.hpp>
#include <Transaction.hpp>
#include <ServiceRequest.hpp>


void signTX(Key* key, ServiceRequest* tx){
	tx->removeSignatureSerialization();
	std::stringstream serialized_string;	
	{
		boost::archive::text_oarchive out_archive(serialized_string);

		out_archive << *tx;
	}
	unsigned char size;
	tx->setSignature(key->sign(reinterpret_cast<unsigned char*>(const_cast<char *>(serialized_string.str().c_str())), serialized_string.str().length(), size));
	tx->setSignatureSize(size);

	tx->addSignatureSerialization();
}

#endif
