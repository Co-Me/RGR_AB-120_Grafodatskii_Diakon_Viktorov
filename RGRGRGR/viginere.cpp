/*Шифр Вижинера.
* Для шифрования используется таблица NxN, где N - количество символов алфавита, сверху вниз в таблица записываются сдвиги алфавита, как в шифре Цезаря.
* Под исходным текстом записывается ключ, зашифрованная буква исходного текста находится в таблице на пересечении этой буквы и буквы ключа, стоящей под ней.
*/
#include <iostream>
#include <string>
#include "viginere.h"
#include "inpout.h"

using namespace std;
using namespace N;

string alpbig = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string alpsmall = "abcdefghijklmnopqrstuvwxyz";

string Viginere::phraseGen(string text, string key) {
    string phrase = "";
    int n = 0;

    for (char c : text) {
        if (isalpha(c)) {
            while (!isalpha(key[n % key.size()])) n++;
            phrase += key[n++ % key.size()];
        }
        else phrase += ' ';
    }

    return phrase;
}

string Viginere::encode_viginere(string text, string key) {
    string result = "";
    int i = 0;
    string alp;
    string phrase = phraseGen(text, key);

    for (size_t i = 0; i < text.size(); ++i) {
        if (!isalpha(text[i])) {
            result += text[i];
            continue;
        }
        if (tolower(text[i]) == text[i]) {
            alp = alpsmall;
            phrase[i] = tolower(phrase[i]);
        }
        else {
            alp = alpbig;
            phrase[i] = toupper(phrase[i]);
        }
        result += alp[(alp.find(text[i]) + alp.find(phrase[i])) % alp.size()];
    }
    Inpout io;
    io.writeOutput(text, result, "Viginere", 1, key);
    return result;
}

string Viginere::decode_viginere(string text, string key) {
    string result = "";
    int i = 0;
    string alp;
    string phrase = phraseGen(text, key);

    for (size_t i = 0; i < text.size(); ++i) {
        if (!isalpha(text[i])) {
            result += text[i];
            continue;
        }
        if (tolower(text[i]) == text[i]) {
            alp = alpsmall;
            phrase[i] = tolower(phrase[i]);
        }
        else {
            alp = alpbig;
            phrase[i] = toupper(phrase[i]);
        }
        result += alp[(alp.find(text[i]) - alp.find(phrase[i]) + alp.size()) % alp.size()];
    }

     Inpout io;
     io.writeOutput(text, result, "Viginere", 2, key);
     return result;
}

string Viginere::viginere(int option, string text, string key) {
    if (option == 1) return encode_viginere(text, key);
    else if (option == 2) return decode_viginere(text, key);
}