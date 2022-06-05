/* Шифр перестановки "скитала".
* На условный стержень цииндрической формы определенного диаметра наматывается полоска бумаги,вдоль стержня записывается сообщение, на развернутой бумажке получается зашифрованный текст
* Для расшифровки необходимо знать диаметр стержня
*/
#include <iostream>
#include <string>
#include <vector>
#include "skital.h"
#include "inpout.h"

using namespace std;
using namespace N;

#define ENCODE 1
#define DECODE 2

string Skital::textParse(string text) {
	string parsedText = "";

	for (char i : text) {
		i = toupper(i);
		parsedText.push_back(i);
	}

	return parsedText;
}

string Skital::skital(int option, string text, string keystr) {
	int key = stoi(keystr);;

	int len = text.size() / key + bool(text.size() % key);
	vector<vector<char>> core(key, vector<char>(len, ' '));
	string result = "";


	if (option == ENCODE) {
		int n = 0;
		for (int i = 0; i < key; ++i) {
			for (int j = 0; j < len; ++j) {
				if (n == text.size()) break;
				core[i][j] = text[n++];
			}
		}

		for (int j = 0; j < len; ++j) {
			for (int i = 0; i < key; ++i) {
				result.push_back(core[i][j]);
			}
		}

	}
	else if (option == DECODE) {
		int n = 0;
		for (int j = 0; j < len; ++j) {
			for (int i = 0; i < key; ++i) {
				if (n == text.size()) break;
				core[i][j] = text[n++];
			}
		}

		for (int i = 0; i < key; ++i) {
			for (int j = 0; j < len; ++j) {
				result.push_back(core[i][j]);
			}
		}
	}
	Inpout io;
	io.writeOutput(text, result, "Skital", option, keystr);
	return result;
}