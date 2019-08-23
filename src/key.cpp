#include <key.hpp>

Key::Key(){}

Key::~Key(){}

void Key::setKeyIndex(unsigned int key_index){
    this->key_index = key_index;
}

void Key::setKeyPair(EC_KEY *key_pair){
    this->key_pair = key_pair;
}