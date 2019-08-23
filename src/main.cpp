#include <stdio.h>

#include <key.hpp>
#include <wallet.hpp>

using namespace std;

int main(){
    Wallet *wallet = new Wallet();
    Key *key = wallet->getKey();
    

    return 0;
}