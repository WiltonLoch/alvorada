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

	template<class T>void signTransaction(std::shared_ptr<Key> key, std::shared_ptr<T> tx){
		tx->removeHashSerialization();
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
		tx->addHashSerialization();
	}

};
#endif
