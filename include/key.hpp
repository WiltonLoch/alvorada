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
        EC_KEY* key_pair;
        unsigned int key_index;
        unsigned char* address;

        //!Cria um endereço (padrão Bitcoin) através da chave pública
        unsigned char* criarEndereco();

    public:
        Key();
        ~Key();

        //!Returns the address generated from the public key
        unsigned char* getEndereco();

        //!Prints the private key in the stdout
        void printPublicKey();

        //!Prints the private key in the stdout
        void printPrivateKey();

        //!Set the key index for possible further generation reference
        void setKeyIndex(unsigned int key_index);
        
        //!Set the key index for possible further generation reference
        unsigned int getKeyIndex();
        
        //!Set the key pair used for the signatures
        void setKeyPair(EC_KEY *key_pair);

        //!Signs a data chunk with the private key
        void sign();

};

#endif