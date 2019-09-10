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
	std::stringstream filename;
	/* tx_req->setLockModel(2); */
	/* filename << "0x" << std::hex << std::uppercase << std::uppercase << tx_req->getHash()[0]; */
	/* printf("filename: %s\n", filename.str().c_str()); */
	std::ofstream exit_stream("tx_req_serial");
	{
		boost::archive::binary_oarchive out_archive(exit_stream);
		out_archive << *tx_req;
	}

	std::ifstream in_stream("tx_req_serial");
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
