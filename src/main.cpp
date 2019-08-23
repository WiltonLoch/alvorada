#include <stdio.h>

#include <key.hpp>
#include <wallet.hpp>

using namespace std;

int main(){
    Wallet *wallet = new Wallet();
    Key *key = wallet->getKey(0);

    // printf("priv: %s\n", BN_bn2hex(const_cast<const BIGNUM*>(priv)));
    // printf("pub: %s\n", EC_POINT_point2hex(curve, pub, POINT_CONVERSION_COMPRESSED, context));



    return 0;
}