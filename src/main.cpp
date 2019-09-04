#include <stdio.h>
#include <fstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

#include <Key.hpp>
#include <Wallet.hpp>
#include <Transaction.hpp>
#include <ServiceRequest.hpp>
#include <GraphFacade.hpp>
#include <bitset>
#include <iostream>

int main(){
	Wallet *wallet = new Wallet();
	Key *key = wallet->getKey();

	std::ofstream exit_stream("tx_req_serial");

	ServiceRequest *tx_req = new ServiceRequest(1, key->getAddress(), 0, 1, "teste_grafo");

	{
		boost::archive::binary_oarchive out_archive(exit_stream);
		out_archive << *tx_req;
	}

   /* for(int i = 0; i < data_size; i++){ */
	    /* std::bitset<32> bitteste (teste[i]); */
	    /* std::cout << bitteste.to_string() << std::endl; */
   /*  } */

	return 0;
}
