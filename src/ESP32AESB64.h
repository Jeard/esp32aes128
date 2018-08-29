#ifndef ESP32_AES_B64_H
#define ESP32_AES_B64_H

class __AesB64{
    private:

    public:
        char*   encry_arr2arr(char *charry, char * key);
        String  encry_arr2str(char *charry, char * key);
        void    add_padding(char *rsltn_ary,size_t padding_len, size_t org_array_len);
};

#endif
