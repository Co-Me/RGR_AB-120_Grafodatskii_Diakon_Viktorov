/*Шифр Вижинера.
* Для шифрования используется таблица NxN, где N - количество символов алфавита, сверху вниз в таблица записываются сдвиги алфавита, как в шифре Цезаря.
* Под исходным текстом записывается ключ, зашифрованная буква исходного текста находится в таблице на пересечении этой буквы и буквы ключа, стоящей под ней.
*/
#include <iostream>
#include <string>
#include "viginer.h"
#include "inpout.h"

using namespace std;
using namespace N;

string alpbig = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string alpsmall = "abcdefghijklmnopqrstuvwxyz";

string Viginer::phraseGen(string text, string key) {
    string phrase = "";
    int n = 0;

    while (phrase.size() < text.size()) {
        if (isalpha(key[n % key.size()])) phrase += key[n % key.size()];
        ++n;
    }

    return phrase;
}

string Viginer::viginer(string text, string key) {
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
    io.writeOutput(text, result, "Viginer", 1, key);
    return result;
}

string Viginer::deviginer(string text, string key) {
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
     io.writeOutput(text, result, "Viginer", 2, key);
     return result;
}