#ifndef KEY_H 
#define KEY_H
#include <stdio.h>

#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <openssl/ec.h>
#include <openssl/sha.h>
#include <openssl/rand.h>

class Key{
    private:
        BIGNUM *private_key;
        EC_POINT *public_key;
        unsigned char* endereco;

        unsigned char* criarEndereco();

    public:
        Key();
        ~Key();

        unsigned char* getEndereco();

        void printPublicKey();
        void printPrivateKey();

        void assinar();

};

#endif