#include <Key.hpp>
#include <bitset>
#include <iostream>

Key::Key(){}

Key::Key(char* address){
        EC_GROUP *curve;
	unsigned int error;

    	if((curve = EC_GROUP_new_by_curve_name(NID_secp256k1)) == NULL){
       		error = ERR_get_error();    
        	printf("Error creating the Eliptic curve = 0x%lx\n", error);
    	} 

	EC_POINT * pub_key = EC_POINT_new(curve);

	if(EC_POINT_hex2point(EC_GROUP_new_by_curve_name(NID_secp256k1), reinterpret_cast<const char*>(address), pub_key, BN_CTX_new()) == NULL){
       		error = ERR_get_error();    
	       	printf("Error recovering public key from address\n");
	}

    	if ((key_pair = EC_KEY_new_by_curve_name(NID_secp256k1)) == NULL){
       		error = ERR_get_error();    
        	printf("Error setting the public key = 0x%lx\n", error);
	}

	if (EC_KEY_set_public_key(key_pair, pub_key) != 1){ 
       		error = ERR_get_error();    
        	printf("Error setting the public key = 0x%lx\n", error);
	}
	generateAddress();
}

Key::~Key(){
	EC_KEY_free(key_pair);
	CRYPTO_cleanup_all_ex_data();
	EVP_cleanup();
	if(address != NULL) free(address);
}

void Key::setKeyIndex(unsigned int key_index){
	this->key_index = key_index;
}

unsigned int Key::getKeyIndex(){
	return this->key_index;
}

void Key::setKeyPair(EC_KEY *key_pair){
	this->key_pair = key_pair;
	generateAddress();
}

void Key::generateAddress(){
	const EC_POINT * pub_key = EC_KEY_get0_public_key(key_pair);
	address = EC_POINT_point2hex(EC_GROUP_new_by_curve_name(NID_secp256k1), pub_key, POINT_CONVERSION_COMPRESSED, BN_CTX_new());
}

unsigned char* Key::sign(unsigned char* data, unsigned int data_size, unsigned char &size){
	unsigned char* rawsig = new unsigned char[ECDSA_size(key_pair)];

	unsigned char data_hash[32];
	SHA256(data, data_size, data_hash);	

	if(ECDSA_sign(0, const_cast<const unsigned char*>(data_hash), 32, rawsig, reinterpret_cast<unsigned int*>(&size), key_pair) == 1){
		return rawsig;
	}
	return nullptr;
}

bool Key::verify(unsigned char* data, unsigned int data_size, unsigned char* rawsig, unsigned int signature_size){
	unsigned char data_hash[32];
	SHA256(data, data_size, data_hash);	

    	if(ECDSA_verify(0, const_cast<const unsigned char*>(data_hash), 32, const_cast<const unsigned char*>(rawsig), signature_size, key_pair) == 1) return true;
    return false;
}


char* Key::getAddress(){
	return address;
}
