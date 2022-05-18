#pragma once
#include <string>


using namespace std;
namespace N
{
    class Inpout
    {

    public:
        string readInput();
        void clear();
        void generateInput();
        void writeOutput(string, string, string);
        string readKey();
        int readOption();
    };

}
