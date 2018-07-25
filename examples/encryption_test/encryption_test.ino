#include <ESP32AESB64.h>

__AesB64 aesB64;

uint64_t chipid;
char chip_ID [15];
uint16_t current;
uint16_t voltge;
char encryption_key[] = "bse64aes128esp32";



void setup() {
  Serial.begin(115200);
  chipid = ESP.getEfuseMac();
  sprintf(chip_ID, "ESP32 Chipid= %5i%10i", (uint16_t)(chipid >> 32), (uint32_t)(chipid));
  String encrypted_str = aesB64.encry_charry(chip_ID,encryption_key);
  Serial.println(encrypted_str);}

void loop() {


}
