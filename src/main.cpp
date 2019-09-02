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

	int data_size = 0;

	unsigned char* teste;

	teste = graphFacade->generateRawData(data_size, "teste_grafo");

	/* graphFacade->generateStructure(teste); */

	ServiceRequest *tx_req = new ServiceRequest(1, NULL, 0, 1, data_size, teste);

   /* for(int i = 0; i < data_size; i++){ */
	    /* std::bitset<32> bitteste (teste[i]); */
	    /* std::cout << bitteste.to_string() << std::endl; */
   /*  } */

	return 0;
}
