#include <stdio.h>

#include <Key.hpp>
#include <Wallet.hpp>
#include <Transaction.hpp>
#include <ServiceRequest.hpp>
#include <GraphFacade.hpp>

using namespace std;

int main(){
    Wallet *wallet = new Wallet();
    Key *key = wallet->getKey();

    ServiceRequest *tx_req = new ServiceRequest(1, NULL, 0, 1, 1, NULL);

    GraphFacade *graphFacade = new GraphFacade();

    int a = 0;

    graphFacade->generateRawData(a, "teste_grafo.g");

    return 0;
}