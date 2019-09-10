#include <stdio.h>
#include <bitset>
#include <iostream>
#include <fstream>

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

#include <Key.hpp>
#include <Wallet.hpp>
#include <Transaction.hpp>
#include <ServiceRequest.hpp>
#include <GraphFacade.hpp>
#include <Sign.hpp>
#include <Hash.hpp>
#include <ServiceRequestVerificator.hpp>

int main(){
	std::unique_ptr<Wallet> wallet (new Wallet());
	std::shared_ptr<Key> key (wallet->getKey());

	std::shared_ptr<ServiceRequest> tx_req (new ServiceRequest(1, key->getAddress(), 1, "teste_grafo"));

	signature::signTransaction(key, tx_req);

	hash::hashServiceRequest(tx_req);
	/* tx_req->setLockModel(2); */
	std::stringstream filename;
	filename << "blockchain/" << tx_req->getHash();

	std::ofstream exit_stream(filename.str().c_str());
	{
		boost::archive::binary_oarchive out_archive(exit_stream);
		out_archive << *tx_req;
	}

	std::ifstream in_stream(filename.str().c_str());
	std::shared_ptr<ServiceRequest> tx_req2(new ServiceRequest());
	{
		boost::archive::binary_iarchive in_archive(in_stream);
		in_archive >> *tx_req2;
	}

	printf("ret %d\n", verification::verifyServiceRequest(tx_req2));

   /* for(int i = 0; i < data_size; i++){ */
	    /* std::bitset<32> bitteste (teste[i]); */
	    /* std::cout << bitteste.to_string() << std::endl; */
   /*  } */

	return 0;
}
