#pragma once
#include <string>

using namespace std;
namespace N
{
    class Grons
    {

    public:
        bool isLetter(char);
        char letterTransform(char, int, int);
        void gronsfeldCipher(int, string, string);
    };

}