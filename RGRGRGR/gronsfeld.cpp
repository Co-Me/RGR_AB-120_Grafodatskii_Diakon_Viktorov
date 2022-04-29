/*
Шифр Гронсфельда использует алфавит и числовой ключ для шифровки. Имеем числовой ключ, если он короче фразы, то он зацикливается. Под буквами исходного текста по порядку записываются цифры ключа,
они указывают на то, на сколько позиций вправо (влево при дешифровке) нужно сдвинуть букву в алфавите.
Алфавит цикличен.
*/
#include <iostream>
#include <vector>
#include <string>
#include "gronsfeld.h"

using namespace std;

#define ENCODE 1
#define DECODE 2

bool isLetter(char letter) {
	if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z')) {
		return true;
	}

	else {
		return false;
	}
}

char letterTransform(char letter, int move, int option) {
	if (!isLetter(letter)) {
		return letter;
	}

	int sign = 0;
	if (option == ENCODE) {
		sign = 1;
	}
	else if (option == DECODE) {
		sign = -1;
	}

	if (letter >= 'a' && letter <= 'z') {
		return char((letter - 'a' + sign * move + 26) % 26 + 'a');
	}
	else if (letter >= 'A' && letter <= 'Z') {
		return char((letter - 'A' + sign * move + 26) % 26 + 'A');
	}
}

void gronsfeld(int option) {
	string key = "";
	string inText = "";
	string outText = "";
	size_t keyIndex = 0;

	cout << "Text: ";
	getline(cin, inText);
	getline(cin, inText);

	cout << "Key: ";
	cin >> key;

	for (size_t i = 0; i < inText.size(); ++i) {
		outText.push_back(letterTransform(inText[i], key[keyIndex % key.size()] - '0', option));
		if (outText.back() == inText[i]) {
			--keyIndex;
		}
		++keyIndex;
	}

	cout << outText;
}