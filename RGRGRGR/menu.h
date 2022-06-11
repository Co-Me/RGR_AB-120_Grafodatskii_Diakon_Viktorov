#pragma once
#include <string>
#include <vector>


using namespace std;
namespace N
{
    class Menu
    {

    public:

		enum class Command
		{
			EXIT,
			BACK,
			GRONSFELD,
			PLAYFAIR,
			SCYTALE,
			CAESAR,
			VIGINERE,
			ATBASH,
			FASTCHECK,
			PRINT,
			CLR,
			CLS,
			HELP,
			CONSOLE,
			FILE,
			RANDOM,
			ENCODE,
			DECODE,
			INCORRECT
		};

        void help();
        Command identifyCommand(string);
		void main();

		void cipher(Command, string);

		void inp(Command, Command, string, string);;

		void type(Command, Command, Command);

		void fastcheck();


    };


}
