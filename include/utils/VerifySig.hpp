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
#include <ServiceProposal.hpp>

namespace signature{

	template<class T> bool verifySig(std::shared_ptr<Key> key, std::shared_ptr<T> obj){
		obj->removeHashSerialization();
		obj->removeSignatureSerialization();

		std::stringstream serialized_string;
		{
			boost::archive::binary_oarchive out_archive(serialized_string);

			out_archive << *obj;
		}

		obj->addSignatureSerialization();
		obj->addHashSerialization();

		return key->verify(reinterpret_cast<unsigned char*>(const_cast<char *>(serialized_string.str().c_str())), serialized_string.str().length(), obj->getSignature(), static_cast<unsigned int>(obj->getSignatureSize()));
	}
}

#endif
