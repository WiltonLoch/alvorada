#include <stdio.h>
#include <bitset>
#include <iostream>
#include <fstream>

#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

#include <Key.hpp>
#include <Wallet.hpp>
#include <Transaction.hpp>
#include <ServiceRequest.hpp>
#include <GraphFacade.hpp>
#include <Sign.hpp>
#include <Hash.hpp>
#include <Block.hpp>

#include <ServiceRequestVerificator.hpp>
#include <BlockVerificator.hpp>

int main(){
	std::unique_ptr<Wallet> wallet (new Wallet());
	std::shared_ptr<Key> key (wallet->getKey());

	std::shared_ptr<ServiceRequest> tx_req (new ServiceRequest(1, key->getAddress(), 0, "teste_grafo"));
	std::shared_ptr<ServiceRequest> tx_req1 (new ServiceRequest(1, key->getAddress(), 1, "teste_grafo"));
	std::shared_ptr<ServiceRequest> tx_req2 (new ServiceRequest(1, key->getAddress(), 1, "teste_grafo"));
	/* std::shared_ptr<ServiceProposal> tx_req_b (new ServiceProposal(1, key->getAddress())); */

	std::shared_ptr<Block> block (new Block());
	std::shared_ptr<Block> block2 (new Block());

	signature::sign(key, tx_req);
	signature::sign(key, tx_req1);
	signature::sign(key, tx_req2);
	hash::hash(tx_req);
	hash::hash(tx_req1);
	hash::hash(tx_req2);
	block->addTx(tx_req);
	block->addTx(tx_req1);
	block->addTx(tx_req2);

	block->createMerkleTree();

	hash::hash(block);
	printf("return: %d\n", verification::verifyBlock(block));
	block->store();
	/* /1* printf("tx_req_hash: %s\n", tx_req->getHexHash()); *1/ */
	/* std::stringstream filename; */
	/* filename << "blockchain/" << block->getHexHash(); */
	/* /1* printf("ext_hash: %s\n", block->getHexHash()); *1/ */

	/* std::ofstream exit_stream(filename.str().c_str()); */
	/* { */
	/* 	boost::archive::binary_oarchive out_archive(exit_stream); */
	/* 	out_archive << *block; */
	/* } */
	/* std::ifstream in_stream(filename.str().c_str()); */
	/* { */
	/* 	boost::archive::binary_iarchive in_archive(in_stream); */
	/* 	in_archive >> *block2; */
	/* } */

	/* printf("ret %d\n", verification::verifyServiceRequest(tx_req2)); */

   /* for(int i = 0; i < data_size; i++){ */
	    /* std::bitset<32> bitteste (teste[i]); */
	    /* std::cout << bitteste.to_string() << std::endl; */
   /*  } */

	return 0;
}
