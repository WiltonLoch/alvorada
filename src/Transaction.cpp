#include <Transaction.hpp>
#include <cstring>

Transaction::Transaction(unsigned int version, unsigned char *address, unsigned char tx_type){
    this->version = version;
    this->address = address;
    this->tx_type = tx_type;
}

Transaction::Transaction(unsigned char* raw_tx){
    memcpy(&version, raw_tx, sizeof(unsigned int));
    memcpy(address, raw_tx, 20);
    memcpy(&signature_size, raw_tx, sizeof(unsigned char));
    memcpy(signature, raw_tx, 9);
    memcpy(&tx_type, raw_tx, sizeof(unsigned char));
}

Transaction::~Transaction(){}

unsigned char* Transaction::generateRawCommomData(){
    //the initial size of the raw data is the sum of the commom information of all transactions:
    //version(4 byte) + address(20 bytes) + signature size(1 bytes) + signature(9 bytes) + type(1 byte)
    unsigned char* raw_tx = new unsigned char[35];
    memcpy(raw_tx, &version, sizeof(unsigned int));
    memcpy(raw_tx, address, 20);
    memcpy(raw_tx, &signature_size, sizeof(unsigned char));
    memcpy(raw_tx, signature, 9);
    memcpy(raw_tx, &tx_type, sizeof(unsigned char));

    return raw_tx;
}
    

