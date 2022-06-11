#pragma once
#include <vector>
#include <string>

using namespace std;
namespace N
{
    class Caesar
    {

    public:
        string encode_caesar(string);
        string decode_caesar(string);
        string caesar(int, string);
    };

}