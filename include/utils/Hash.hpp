#ifndef UTILS_VERIFY_SIG_H 
#define UTILS_VERIFY_SIG_H

#include <fstream>
#include <iostream>
#include <sstream>

#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/export.hpp>
#include <openssl/sha.h>

#include <Key.hpp>
#include <Transaction.hpp>
#include <ServiceRequest.hpp>

namespace hash{

	template<class T> void hash(std::shared_ptr<T> obj){
		obj->removeHashSerialization();

		std::stringstream serialized_string;
		{
			boost::archive::binary_oarchive out_archive(serialized_string);
			out_archive << *obj;
		}
		unsigned char* hash = new unsigned char[32];
		SHA256(reinterpret_cast<const unsigned char*>(serialized_string.str().c_str()), serialized_string.str().length(), hash);
		obj->setHash(hash);

		obj->addHashSerialization();

	}

}

#endif
