#include<jbits/stdc++.h>

class Chave {
    private:
        BIGNUM *privada;
        EC_POINT publica;
        unsigned char* endereço;
    public:
        Chave();
        ~Chave();
}