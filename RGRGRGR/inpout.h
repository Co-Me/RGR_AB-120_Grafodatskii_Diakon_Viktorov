#pragma once
#include <string>
#include <vector>


using namespace std;
namespace N
{
    class Inpout
    {

    public:
        string readText();
        void clear();
        string generateInput(int, string name = "");
        void writeOutput(string, string, string, int, string);
        string readKey();
        bool checkText(string, string option = "");
        pair<string, string> readFile(bool);
        bool pass();
        int countLines();

        void print();

    private:
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
        string correct = "1111";
    };


}
