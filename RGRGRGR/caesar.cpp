/*Ўифр ÷езар€ Ч это вид шифра подстановки, в котором каждый символ в открытом тексте замен€етс€
символом наход€щимс€ на некотором посто€нном числе позиций левее или правее него в алфавите.*/

#include <iostream>
#include <string>
#include "caesar.h"
#include "inpout.h"

using namespace std;
using namespace N;

string Caesar::encode_caesar(string str) {

    string plaintext = str;
    int lenth;

    lenth = str.size();

    for (int i = 0; i < lenth; i++) {
        if (!isalpha(str[i])) continue;
        if (tolower(str[i]) >= 'x') {
            str[i] = str[i] - 26;
            str[i] += 3;
        }
        else {
            if (str[i] == 32) {
                str[i] = 32;
            }
            else {
                str[i] += 3;
            }

        }
    }
    Inpout io;
    io.writeOutput(plaintext, str, "Caesar", 1, "No key");
    return str;
}

string Caesar::decode_caesar(string str) {

    string ciphertext = str;
    int lenth;

    lenth = str.size();

    for (int i = 0; i < lenth; i++) {
        if (!isalpha(str[i])) continue;
        if ((tolower(str[i]) <= 'c') && (str[i] != 32)) {
            str[i] = str[i] + 26;
            str[i] -= 3;
        }
        else {
            if (str[i] == 32) {
                str[i] = 32;
            }
            else {
                str[i] -= 3;
            }

        }
    }
    Inpout io;
    io.writeOutput(ciphertext, str, "Caesar", 2, "No key");
    return str;
}

string Caesar::caesar(int option, string text) {
    if (option == 1) return encode_caesar(text);
    else if (option == 2) return decode_caesar(text);
}