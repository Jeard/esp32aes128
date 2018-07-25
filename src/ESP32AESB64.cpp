#include "ESP32AESB64.h"

String __AesB64::encry_charry(char *charry, char * key) {
  _len_charry = strlen(charry);
   _k = _len_charry / 16;
   _modulo_16 = _len_charry % 16;
   _len_padding = 0;
  if (_modulo_16 != 0) {
    _k= _k+ 1;
    _len_padding = 16 - _modulo_16;}
  char array_2_encr [_k* 16];
  memcpy (array_2_encr, charry, _len_charry );
  if (_modulo_16 != 0) {
    add_padding(array_2_encr, _len_padding, _len_charry );}
   uint8_t encrypted_array [(_k* 16) + 1]; 
    for (int i = 0; i < _k ;i++) {
    char block [16];
    memcpy(block, array_2_encr + ((16 * i)), 16);
    char *input = block;
    uint8_t output[16];
    mbedtls_aes_init( &aes );
    mbedtls_aes_setkey_enc( &aes, (const unsigned char*) key, strlen(key) * 8 );
    mbedtls_aes_crypt_ecb(&aes, MBEDTLS_AES_ENCRYPT, (const unsigned char*)input, output);
    mbedtls_aes_free( &aes );
    memcpy(encrypted_array + (16 * i), output, 16);}
    return (b_64.encode(encrypted_array, (_k* 16)));}

void __AesB64::add_padding(char *rsltn_ary,uint8_t padding_len, uint16_t org_array_len) {
  for (uint8_t i = 0; i < padding_len; i++) {
    uint16_t val = (org_array_len + i);
    rsltn_ary[val] = '\0';}}
