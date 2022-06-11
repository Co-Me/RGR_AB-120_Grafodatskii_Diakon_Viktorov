#pragma once
#include <string>

using namespace std;
namespace N
{
    class Viginere
    {

    public:
        string encode_viginere(string, string);
        string decode_viginere(string, string);
        string phraseGen(string, string);
        string viginere(int, string, string);
    };

}