#pragma once
#include <string>


using namespace std;
namespace N
{
    class Inpout
    {

    public:
        string correct = "1111";
        string readInput();
        void clear();
        string generateInput(int, string name = "");
        void writeOutput(string, string, string, int, string);
        string readKey();
        int readOption(string);
        bool checkText(string, string option = "");
        string textParse(string);
        bool pass();
    };

}
