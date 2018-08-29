#include <ESP32AESB64.h>

__AesB64 aesB64;

uint64_t chipid;
char chip_ID [40];
char encryption_key[] = "bse64aes128esp32";



void setup() {
  Serial.begin(115200);
  chipid = ESP.getEfuseMac();
  sprintf(chip_ID, "ESP32 Chipid= %i%i", (uint16_t)(chipid >> 32), (uint32_t)(chipid));
  String encrypted_str = aesB64.encry_arr2str(chip_ID,encryption_key);
  char* encrypted_arr = aesB64.encry_arr2arr(chip_ID,encryption_key);
  Serial.println(encrypted_str);
  Serial.println(encrypted_arr);
  
  }

void loop() {


}
