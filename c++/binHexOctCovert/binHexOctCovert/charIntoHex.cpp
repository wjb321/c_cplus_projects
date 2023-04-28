#include <iostream>
#include <typeinfo> //check the type of data
#include <string>
using namespace std;


int hexCharToInt1(char c) {
    if (c >= '0' && c <= '9') {
        std::cout << "return " << std::hex << typeid(c - '0').name() << " Value " << c - '0' << std::endl;
        return c - '0';
    }
    else if (c >= 'A' && c <= 'F') {
        std::cout << "return " << std::hex << typeid(c - 'A' + 10).name() << " Value " << c - 'A' + 10 << std::endl;
        return c - 'A' + 10;
    }
    else if (c >= 'a' && c <= 'f') {
        std::cout << "return " << std::hex << typeid(c - 'a' + 10).name() << " Value " << c - 'a' + 10 << std::endl;
        return c - 'a' + 10;
    }
    else {
        return 0; // 非法字符，返回0
    }
}

// 将一个长度为6的16进制字符数组转换为对应的32位16进制数
uint32_t hexArrayToUInt321(char hexArray[]) {
    uint32_t result = 0;
    for (int i = 0; i < 6; i++) {
        int hexValue = hexCharToInt1(hexArray[i]);
        result |= (hexValue << ((5 - i) * 4)); // 将每个16进制字符转换为4位二进制数，然后左移对应的位数
    }
    return result;
}
int main1()
{
    char hexArray[6] = { 'A', '6', '3', 'E', 'F', 'D' };
    uint32_t value = hexArrayToUInt321(hexArray);
    std::cout << "format of the data " << std::hex << typeid(value).name() << "Value in hex: 0x " <<value << std::endl;

    return 0;
}