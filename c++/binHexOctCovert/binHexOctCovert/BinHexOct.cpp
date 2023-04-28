#include <iostream>
#include <typeinfo> //check the type of data
#include <string>
using namespace std;
char  buffer[33];  //用于存放转换好的十六进制字符串，可根据需要定义长度
char* inttohex(int  aa);

uint32_t decToHex(unsigned int dec)
{
    uint32_t hex = 0;
    int i = 0;
    while (dec > 0)
    {
        hex += (dec % 16) << (4 * i);
        dec /= 16;
        i++;
    }
    return hex;
}

int hexCharToInt(char c) {
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
uint32_t hexArrayToUInt32(char hexArray[]) {
    uint32_t result = 0;
    for (int i = 0; i < 6; i++) {
        int hexValue = hexCharToInt(hexArray[i]);
        result |= (hexValue << ((5 - i) * 4)); // 将每个16进制字符转换为4位二进制数，然后左移对应的位数
    }
    return result;
}


int main()
{
    char* hex1;
    uint32_t dec = 7777777;
    uint8_t can_data[8];
    hex1 = inttohex(dec); // return the hex with char data type
    cout << "hex " << hex1 <<" " <<" hex to int "<< stoi(hex1, nullptr, 16) << " " << typeid(hex1).name() << endl;
    uint32_t value = hexArrayToUInt32(hex1);
    std::cout << " format of the data " << std::hex << typeid(value).name() << " Value in hex: 0x " << value << std::endl;

    decToHex(dec);
    std::cout << " decToHex(dec) " << std::hex << typeid(decToHex(dec)).name() << " Value in hex: 0x " << decToHex(dec) << std::endl;
	system("pause");
	return 0;
}


char* inttohex(int  aa)
{
    static  int  i = 0;
    if (aa < 16)             //递归结束条件 
    {
        if (aa < 10)         //当前数转换成字符放入字符串 
            buffer[i] = aa + '0';
        else
            buffer[i] = aa - 10 + 'A';
        buffer[i + 1] = '\0';  //字符串结束标志 
    }
    else
    {
        inttohex(aa / 16);   //递归调用 
        i++;                 //字符串索引+1 
        aa %= 16;            //计算当前值
        if (aa < 10)         //当前数转换成字符放入字符串 
            buffer[i] = aa + '0';
        else
            buffer[i] = aa - 10 + 'A';
    }
    return  (buffer);
}
