#ifndef ESP32_AES_B64_H
#define ESP32_AES_B64_H

#include "base64.h"
#include <mbedtls/aes.h>




class __AesB64{
    private:
        uint8_t _len_charry = 0;
        uint8_t _k = 0;
        uint8_t _modulo_16 =0;
        uint8_t _len_padding=0;
        base64 b_64;
        mbedtls_aes_context aes;

    public:
        String  encry_charry(char *charry, char * key);
        void    add_padding(char *rsltn_ary,uint8_t padding_len, uint16_t org_array_len);
};


#endif
