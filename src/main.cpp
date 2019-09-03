#include <stdio.h>

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

	GraphFacade *graphFacade = new GraphFacade();

	ServiceRequest *tx_req = new ServiceRequest(1, key->getAddress(), 0, 1, "teste_grafo");

   /* for(int i = 0; i < data_size; i++){ */
	    /* std::bitset<32> bitteste (teste[i]); */
	    /* std::cout << bitteste.to_string() << std::endl; */
   /*  } */

	return 0;
}
