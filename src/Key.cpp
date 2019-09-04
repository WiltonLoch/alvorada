#include <Key.hpp>

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

char* Key::getAddress(){
	return address;
}
