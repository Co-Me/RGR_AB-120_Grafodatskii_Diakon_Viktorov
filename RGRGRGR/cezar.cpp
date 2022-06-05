/*Ўифр ÷езар€ Ч это вид шифра подстановки, в котором каждый символ в открытом тексте замен€етс€
символом наход€щимс€ на некотором посто€нном числе позиций левее или правее него в алфавите.*/

#include <iostream>
#include <string>
#include "cezar.h"
#include "inpout.h"

using namespace std;
using namespace N;

string Cezar::textParse(string text) {
    string parsedText = "";

    for (char i : text) {
        i = toupper(i);
        parsedText.push_back(i);
    }

    return parsedText;
}

string Cezar::cezar(string str) {
    str = textParse(str);
    string plaintext = str;
    int lenth;

    lenth = str.size();

    for (int i = 0; i < lenth; i++) {
        if (str[i] >= 'X') {
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
    io.writeOutput(plaintext, str, "Cezar", 1, "No key");
    return str;
}

string Cezar::decezar(string str) {
    str = textParse(str);
    string ciphertext = str;
    int lenth;

    lenth = str.size();

    for (int i = 0; i < lenth; i++) {

        if ((str[i] <= 'C') && (str[i] != 32)) {
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
    io.writeOutput(ciphertext, str, "Cezar", 2, "No key");
    return str;
}