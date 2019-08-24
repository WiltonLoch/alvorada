#ifndef WALLET_H
#define WALLET_H

#include <stdio.h>
#include <key.hpp>

typedef unsigned char byte;

//! HDWallet class, destined to handle the creation and storage of keys
/**
*The Wallet class implements a HDWallet according to Bitcoin implementation model.
*A cryptographic secure random number and a salt are used for the deterministic creation of milions of
*child private and public keys. For more information about this specific type of wallet, refer to the Bitcoin Documentation or O'Reily's "Mastering Bitcoin" book.
*/
class Wallet{
    private:
        //! Initial Private key derived from the Seed
        BIGNUM *generator_private_key;

        //! Initial Public key derived from the Seed
        EC_POINT *generator_public_key;

        //! Initial Public key derived from the Seed
        BIGNUM *generator_chaincode;

        //!BIGNUM context to hold temporary variables useful for the lib
        BN_CTX *context;

        //!Curve used in the EC multiplication
        EC_GROUP *curve;
    
        //! Tries to read 4 byte key index from the disk
        int recoverPrivateKeyIndex(unsigned int *key_index);

        //! Tries to read the 64 bytes seed from the disk
        int receiveSeed(byte** seed);

        //! Create a 64 bytes seed from a pseudo-random cryptographic safe entropy source provided by the system
        int generateSeed(byte** seed);

        //! Generates the public key(33 bytes in the compressed form) from an existing private key
        int generatePublicKey(BIGNUM *private_key, EC_POINT **public_key);

        //! Converts an uint to the equivalent bytes of unsigned char data
        void uint2uchar32(byte* retorno, unsigned int);

        //! Initialize the genetors(private, public key and chaincode) with direct data from the hashed seed
        int initializeGenerators();

        //! Creates a new private key
        int generatePrivateKey(BIGNUM **destination, unsigned int key_index);

    public:
        Wallet();
        ~Wallet();       
        
        //!Returns a Key object created either from the seed or recovered from the disk        
        Key* getKey(unsigned int key_index = 0);        
};

#endif