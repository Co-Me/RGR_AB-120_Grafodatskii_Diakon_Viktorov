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

string alp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string Viginer::viginer(string text, string key) {
    string result = "";
    int i = 0;

    for (size_t i = 0; i < text.size(); ++i) {
        result += alp[(alp.find(text[i]) + alp.find(key[i % key.size()])) % alp.size()];
    }
    Inpout io;
    io.writeOutput(text, result, "Viginer", 1, key);
    return result;
}

string Viginer::deviginer(string text, string key) {
    string result = "";
    int i = 0;

    for (size_t i = 0; i < text.size(); ++i) {
        result += alp[(alp.find(text[i]) - alp.find(key[i % key.size()]) + alp.size()) % alp.size()];
    }

     Inpout io;
     io.writeOutput(text, result, "Viginer", 2, key);
     return result;
}