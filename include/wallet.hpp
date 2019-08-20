#ifndef WALLET_H
#define WALLET_H

#include <stdio.h>
#include <key.hpp>

class Wallet{
    private:
        unsigned char[32] chaincode;
        int key_index;
        unsigned char[32] private_key_level_0;
        unsigned char[32] public_key_level_0;
        unsigned char[32] chaincode_level_0;
    
        //! Tenta ler a chave do disco
        unsigned char[32] readKey();
        unsigned char[64] readSeed();
        unsigned char[64] createSeed();
        unsigned char[32] getPublicKey();
        void uint2uchar32(unsigned char** retorno, );
        

    public:
        Wallet();
        ~Wallet();

        getKey();
        

        createKey()
}

#endif