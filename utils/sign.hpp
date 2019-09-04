#ifndef UTILS_SIGN_H
#define UTILS_SIGN_H

#include <fstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
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
	printf("st: %s-\n", serialized_string.str().c_str());
	unsigned char size;
	tx->setSignature(key->sign(reinterpret_cast<unsigned char*>(const_cast<char *>(serialized_string.str().c_str())), serialized_string.str().length(), size));
	tx->setSignatureSize(size);
	/* unsigned char* teste = tx->getSignature(); */

   /* for(int i = 0; i < size; i++){ */
	    /* std::bitset<32> bitteste (teste[i]); */
	    /* std::cout << bitteste.to_string() << std::endl; */
   /*  } */

	tx->addSignatureSerialization();
}

#endif
