#include <Arduino.h>
#include <mbedtls/aes.h>
extern "C"{
#include "cencode.h"
}
#include "ESP32AESB64.h"

mbedtls_aes_context aes;

/**
 * convert input data to AES128 encrypted base64
 * @param charry char *
 * @param key char *
 * @return char *
 */

char* __AesB64::encry_arr2arr(char *charry, char * key) {
  size_t _len_charry = strlen(charry);
  size_t _k = _len_charry / 16;
  size_t _modulo_16 = _len_charry % 16;
  if (_modulo_16 != 0) {
    _k= _k+ 1;
    }
  size_t length=(_k* 16);
  char* array_2_encr=(char*) malloc(length);
  memset(array_2_encr, 0x00, length);
  memcpy (array_2_encr, charry, _len_charry );
  if (_modulo_16 != 0) {
    array_2_encr[(_len_charry+1)]=0x80;
    }
  uint8_t* encrypted_array=(uint8_t*) malloc(length+1);
  char* block =(char*)malloc(16);
  uint8_t* output=(uint8_t*)malloc(16); 
  mbedtls_aes_init( &aes );
  mbedtls_aes_setkey_enc( &aes, (const unsigned char*) key, strlen(key) * 8 );
  for (int i = 0; i < _k ;i++) {
    memcpy(block, array_2_encr + ((16 * i)), 16);
    if(block!=NULL){
    mbedtls_aes_crypt_ecb(&aes, MBEDTLS_AES_ENCRYPT, (const unsigned char*)block, output);}
    memcpy(encrypted_array + (16 * i), output, 16);
    }
  mbedtls_aes_free( &aes );
  size_t _bufferSize=((length*1.6f)+1);
  char * buffer = (char *) malloc(_bufferSize);
  base64_encodestate _state;
  base64_init_encodestate_nonewlines(&_state);
  int len = base64_encode_block((const char *) &encrypted_array[0], length, &buffer[0], &_state);
  len = base64_encode_blockend((buffer + len), &_state);
  return buffer;
}

/**
 * convert input data to AES128 encrypted base64
 * @param charry char *
 * @param key char *
 * @return String
 */
String __AesB64::encry_arr2str(char *charry, char * key) {
  char* encoded_arr=__AesB64::encry_arr2arr(charry, key);
  String base64 = String(encoded_arr);
  free(encoded_arr);
  return base64;
  }
