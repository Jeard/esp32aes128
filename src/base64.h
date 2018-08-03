#ifndef CORE_BASE64_H_
#define CORE_BASE64_H_

#include <WString.h>
#include <stdint.h>

class base64
{
public:
    static String encode(uint8_t * data, size_t length);
    static String encode(String text);
private:
};


#endif /* CORE_BASE64_H_ */
