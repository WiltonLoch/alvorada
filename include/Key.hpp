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
        char *address;

        //!Cria um endereço que trata-se da chave pública comprimida
        void generateAddress();

    public:
        Key();
        ~Key();              

        //!Signs a data chunk with the private key
        void sign(unsigned char* data);

        //!Set the key index for possible further generation reference
        void setKeyIndex(unsigned int key_index);
        
        //!Set the key index for possible further generation reference
        unsigned int getKeyIndex();

        //!Returns the address generated from the public key
        char* getAddress();
        
        //!Set the key pair used for the signatures
        void setKeyPair(EC_KEY *key_pair);

        //!Prints the private key in the stdout
        void printPublicKey();

        //!Prints the private key in the stdout
        void printPrivateKey();  

};

#endif
