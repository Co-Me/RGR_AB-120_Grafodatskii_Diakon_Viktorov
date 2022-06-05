/*���� ��������.
* ��� ���������� ������������ ������� NxN, ��� N - ���������� �������� ��������, ������ ���� � ������� ������������ ������ ��������, ��� � ����� ������.
* ��� �������� ������� ������������ ����, ������������� ����� ��������� ������ ��������� � ������� �� ����������� ���� ����� � ����� �����, ������� ��� ���.
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