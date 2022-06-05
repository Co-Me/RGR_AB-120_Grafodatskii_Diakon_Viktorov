/*јтбаш
* Ўифрование происходит заменой первой буквы алфавита на последнюю, второй на предпоследнюю и т.д.
*/
#include <iostream>
#include <string>
#include "atbash.h"
#include "inpout.h"

using namespace std;
using namespace N;

#define  CODE_ATBASH       "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define  DECODE_ATBASH    "ZYXWVUTSRQPONMLKJIHGFEDCBA"

string Atbash::encode_atbash(string src) {
    string startstring = src;

    for (int i = 0; i < src.size(); ++i) {
        if (isalpha(src[i])) {
            for (int j = 0; ; ++j) {
                if (CODE_ATBASH[j] == toupper(src[i])) {
                    src[i] = (toupper(src[i])) ? DECODE_ATBASH[j] : tolower(DECODE_ATBASH[j]);
                    break;
                }
            }
        }
    }
    Inpout io;
    io.writeOutput(startstring, src, "Atbash", 1, "No key");
    return src;
}

string Atbash::decode_atbash(string src) {
    string startstring = src;

    for (int i = 0; i < src.size(); ++i) {
        if (isalpha(src[i])) {
            for (int j = 0; ; ++j) {
                if (DECODE_ATBASH[j] == toupper(src[i])) {
                    src[i] = (toupper(src[i])) ? CODE_ATBASH[j] : tolower(CODE_ATBASH[j]);
                    break;
                }
            }
        }
    }
    Inpout io;
    io.writeOutput(startstring, src, "Atbash", 2, "No key");
    return src;
}