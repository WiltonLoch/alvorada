#include <stdio.h>

#include <Key.hpp>
#include <Wallet.hpp>
#include <Transaction.hpp>
#include <ServiceRequest.hpp>

using namespace std;

int main(){
    Wallet *wallet = new Wallet();
    Key *key = wallet->getKey();
    

    return 0;
}