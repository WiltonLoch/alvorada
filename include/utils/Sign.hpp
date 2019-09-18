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
#include <ServiceProposal.hpp>

namespace signature{

	template<class T>void sign(std::shared_ptr<Key> key, std::shared_ptr<T> obj){
		obj->removeHashSerialization();
		obj->removeSignatureSerialization();

		std::stringstream serialized_string;	
		{
			boost::archive::binary_oarchive out_archive(serialized_string);

			out_archive << *obj;
		}
		unsigned char size;
		obj->setSignature(key->sign(reinterpret_cast<unsigned char*>(const_cast<char *>(serialized_string.str().c_str())), serialized_string.str().length(), size));
		obj->setSignatureSize(size);

		obj->addSignatureSerialization();
		obj->addHashSerialization();
	}

};
#endif
