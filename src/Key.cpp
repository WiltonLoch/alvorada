#include <Key.hpp>

Key::Key(){}

Key::~Key(){}

void Key::setKeyIndex(unsigned int key_index){
    this->key_index = key_index;
}

unsigned int Key::getKeyIndex(){
    return this->key_index;
}

void Key::setKeyPair(EC_KEY *key_pair){
    this->key_pair = key_pair;
}

void generateAddress(){

}

unsigned char* Key::getAddress(){
	return address;
}
