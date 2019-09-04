#include <Key.hpp>
#include <bitset>
#include <iostream>

Key::Key(){}

Key::~Key(){
	EC_KEY_free(key_pair);
	CRYPTO_cleanup_all_ex_data();
	EVP_cleanup();
	free(address);
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

   for(int i = 0; i < 32; i++){
	    std::bitset<32> bitteste (data_hash[i]);
	    std::cout << bitteste.to_string() << std::endl;
    }

	if(ECDSA_sign(0, const_cast<const unsigned char*>(data_hash), 32, rawsig, reinterpret_cast<unsigned int*>(&size), key_pair) == 1){
		printf("data_size1: %d\n", size);
		return rawsig;
	}
	return nullptr;
}

bool Key::verify(unsigned char* data, unsigned int data_size, unsigned char* rawsig, unsigned int signature_size){
	unsigned char data_hash[32];
	SHA256(data, data_size, data_hash);	

   for(int i = 0; i < 32; i++){
	    std::bitset<32> bitteste (data_hash[i]);
	    std::cout << bitteste.to_string() << std::endl;
    }

	    printf("retorno:");
    	int retorno = ECDSA_verify(0, const_cast<const unsigned char*>(data_hash), 32, const_cast<const unsigned char*>(rawsig), signature_size, key_pair);
    printf("retorno:%d\n", retorno);
    return false;
}


char* Key::getAddress(){
	return address;
}
