#ifndef Transaction_H
#define Transaction_H

class Transaction{
    protected:
        unsigned int version;
        unsigned char *tx_hash;
        unsigned char *address;
        unsigned char signature_size;
        unsigned char *signature;

        unsigned char tx_type;
    public:
        Transaction(unsigned int version, unsigned char *address, unsigned char tx_type);
        Transaction(unsigned char* raw_data);
        ~Transaction();

        unsigned char* generateRawCommomData();
        virtual bool verify() = 0;

        unsigned int getVersion();
        void setVersion(unsigned int version);

        unsigned char* getTxHash();
        void setTxHash(unsigned char* tx_hash);

        unsigned char* getAddress();
        void setAddress(unsigned char* address);

        unsigned char getSignatureSize();
        void setSignatureSize(unsigned char signature_size);

        unsigned char* getSignature();
        void setSignature(unsigned char *signature);

        unsigned char getTxType();
        void setTxType(unsigned char tx_type);

        
};

#endif