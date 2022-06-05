#pragma once
#include <string>
#include <vector>


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
        pair<string, string> readFile(string, bool);
        bool pass();

        vector<string> dict = { "area",
                                "book",
                                "business",
                                "case",
                                "child",
                                "company",
                                "country",
                                "day",
                                "eye",
                                "fact",
                                "family",
                                "government",
                                "group",
                                "hand",
                                "home",
                                "job",
                                "life",
                                "lot",
                                "man",
                                "money",
                                "month",
                                "mother",
                                "Mr",
                                "night",
                                "number",
                                "part",
                                "people",
                                "place",
                                "point",
                                "problem",
                                "program",
                                "question",
                                "right",
                                "room",
                                "school",
                                "state",
                                "story",
                                "student",
                                "study",
                                "system",
                                "thing",
                                "time",
                                "water",
                                "way",
                                "week",
                                "woman",
                                "word",
                                "work",
                                "world",
                                "year" };
    };

}
