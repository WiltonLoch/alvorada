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

        //!Cria um endereço (padrão Bitcoin) através da chave pública
        unsigned char* criarEndereco();

    public:
        Key();
        ~Key();

        //!Retorna o endereço criado pela chave pública em questão
        unsigned char* getEndereco();

        //!Escreve a chave pública na saída padrão
        void printPublicKey();

        //!Escreve a chave privada na saída padrão
        void printPrivateKey();

        //!Assina um conjunto de dados com a chave privada
        void assinar();

};

#endif