#include <iostream>
#include "BASE64.h"

using namespace std;
//возвращает байт одного символв входной строки.
string line_of_bytes(unsigned int ascii){
    string result_1;
    for (int j = 0; j < 8; ++j) {
        result_1 += (ascii % 2 ? '1' : '0');
        ascii /= 2;
    }
    reverse(result_1.begin(), result_1.end());
    return result_1;
}

string Encoding(string line){
    const string Base64Table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
    string outline;
    string bytes;//строка байт всех символов входной строки
    unsigned int sizeofbytes;
    unsigned int sizeofline;//размер входной строки
    unsigned char symbol;//символ введенной строки
    unsigned int ascii;//номер символа введенной строки в кодировке ASCII
    unsigned int index;//номер символа в таблице BASE64
    int res[1000];
    int i(0);
    int count(0);
    //считываем байты символов входной строки
    sizeofline = size(line);
    while (i < sizeofline) {
        symbol = line[i];
        ascii = int(symbol);
        i++;
        bytes += line_of_bytes(ascii);}
    //дописываем нужные нули, если количество бит не кратно 6
    sizeofbytes = size(bytes);
    if (sizeofline % 3 != 0) {
        for(int j(0); j<(6-sizeofbytes%6);j++){
            bytes += '0';
        }
        sizeofbytes = size(bytes);
    }
    while (count<sizeofbytes) {
        if (bytes[count] == '1') { res[count] = 1; }
        else { res[count] = 0; }
        count++;
    }
    for(int n(0);n<sizeofbytes;n+=6){
        index = res[n]*32 + res[n+1]*16 + res[n+2]*8 + res[n+3]*4 + res[n+4]*2 + res[n+5]*1;
        outline += Base64Table[index];
    }
    if(sizeofline % 3 == 1) {
        outline += Base64Table[64];
        outline += Base64Table[64];
    }
    if(sizeofline % 3 == 2) {
        outline += '=';
    }
    return outline;
}

string line_of_bytes_2(unsigned int base_64){
    string result_1;
    for (int j = 0; j < 6; ++j) {
        result_1 += (base_64 % 2 ? '1' : '0');
        base_64 /= 2;
    }
    reverse(result_1.begin(), result_1.end());
    return result_1;
}

string Decoding(string line){
    const string Base64Table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
    string outline;
    string bytes;//строка байт всех символов входной строки
    unsigned int sizeofbytes;
    unsigned int sizeofline;//размер входной строки
    unsigned int base_64;//номер символа введенной строки в кодировке BASE64
    unsigned int index;//номер символа в таблице BASE64
    int res[1000];
    int i(0);
    int count(0);
    //считываем байты символов входной строки
    sizeofline = size(line);
    while (i < sizeofline && line[i] != '=') {
        int j(0);
        while (Base64Table[j] != line[i]) {
            j++;
        }
        base_64 = j;
        i++;
        bytes += line_of_bytes_2(base_64);
    }
    //убираем лишние нули
    sizeofbytes = size(bytes);
    if (line[sizeofline-1] != '=' && sizeofline%4 !=0){
        sizeofbytes= sizeofbytes - (8 - sizeofbytes%8);
    }
    while (line[sizeofline-1] == '='){
        sizeofbytes = sizeofbytes - 2;
        sizeofline = sizeofline - 1;
    }
    while (count<sizeofbytes) {
        if (bytes[count] == '1') { res[count] = 1; }
        else { res[count] = 0; }
        count++;
    }
    for(int n(0);n<sizeofbytes;n+=8){
        index = res[n]*128 + res[n+1]*64 + res[n+2]*32 + res[n+3]*16 + res[n+4]*8 + res[n+5]*4 + res[n+6]*2 + res[n+7];
        outline += char(index);
    }
    return outline;
}