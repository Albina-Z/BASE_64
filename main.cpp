#include <iostream>
#include <string>
#include "BASE64.h"

using namespace std;

int main() {
    string line;
    string result;
    char button;
    cout << "Input line: ";
    getline(cin, line);
    cout << "Input 'E' for encoding(-->base64) or 'D' for decoding(<--base64) : ";
    cin >> button;
    if (button =='E') {
        cout << "Output line: ";
        result = Encoding(line);
        cout << result;
    }
    if (button == 'D'){
        cout << "Output line: ";
        result = Decoding(line);
        cout << result;
    }
    return 0;
}






