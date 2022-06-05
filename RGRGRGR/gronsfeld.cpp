/*
Шифр Гронсфельда использует алфавит и числовой ключ для шифровки. Имеем числовой ключ, если он короче фразы, то он зацикливается. Под буквами исходного текста по порядку записываются цифры ключа,
они указывают на то, на сколько позиций вправо (влево при дешифровке) нужно сдвинуть букву в алфавите.
Алфавит цикличен.
*/
#include <iostream>
#include <vector>
#include <string>
#include "gronsfeld.h"
#include "inpout.h"

using namespace std;
using namespace N;

#define ENCODE 1
#define DECODE 2

bool Grons::isLetter(char letter) { // Является ли символ буквой
	if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z')) {
		return true;
	}

	else {
		return false;
	}
}

char Grons::letterTransform(char letter, int move, int option) { // Преобразоваие символа
	if (!Grons::isLetter(letter)) {
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

string Grons::gronsfeldCipher(int option, string plaintext, string key) {
	Inpout io;

	string ciphertext = "";
	size_t keyIndex = 0;

	for (size_t i = 0; i < plaintext.size(); ++i) {
		ciphertext.push_back(Grons::letterTransform(plaintext[i], key[keyIndex % key.size()] - '0', option));
		if (ciphertext.back() == plaintext[i]) {
			--keyIndex;
		}
		++keyIndex;
	}

	io.writeOutput(plaintext, ciphertext, "Gronsfeld cipher", option, key);
	return ciphertext;

}