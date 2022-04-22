#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

string codeWord = "BAKA MITAI"; // Кодовое слово

void sheetGenerator(vector<vector<char>> &sheet) { // Генерация таблицы для шифрования
	int rowIndex = 0;
	bool alphabet[26] = { false };
	alphabet['J' - 'A'] = true; // Буквы I и J считать за одну для уменьшения алфавита

	for (char i : codeWord) {
		if (i < 'A' || i > 'Z') {
			continue;
		}

		if (!alphabet[i - 'A']) {
			sheet[rowIndex].push_back(i);
			alphabet[i - 'A'] = true;
		}

		if (sheet[rowIndex].size() == 5) {
			sheet.push_back(vector<char>());
			rowIndex++;
		}
	}


	for (size_t i = 0; i < 26; i++) {
		if (!alphabet[i]) {
			sheet[rowIndex].push_back('A' + i);
			alphabet[i] = true;
		}
		if (sheet[rowIndex].size() == 5) {
			sheet.push_back(vector<char>());
			rowIndex++;
		}
	}


	for (size_t i = 0; i < 25; i++) {
		cout << sheet[i / 5][i % 5] << ' ';
		if ((i + 1) % 5 == 0) cout << endl;
	}

 }


void bigramsGenerator(vector<pair<char, char>>& digrams, vector<char> textToEncode) { // Генератор вектора биграмм
	for (size_t i = 0; i < textToEncode.size(); i += 2) {
		digrams.push_back(pair<char, char>(0, 0));
		digrams.back().first = textToEncode[i];

		if (i + 1 == textToEncode.size()) {
			break;
		}

		if (textToEncode[i] == textToEncode[i + 1]) {
			digrams.back().second = ('X');
			i--;
			continue;
		}

		digrams.back().second = textToEncode[i + 1];
	}

	if (digrams.back().second == 0) {
		digrams.back().second = 'X';
	}
}


void textParse(string text, vector<char> &textToEncode) { // Обработка исходного текста, удаление пробелов, замена J на I (позже - перевод в верхний регистр)
	for (char i : text) {
		if (i >= 'A' && i <= 'Z') {
			if (i == 'J') {
				i = 'I';
			}
			textToEncode.push_back(i);
		}
	}
}

//_____________________________________________________________________________________________________________________________________________________________________________________________________
// Что есть: *генерация таблицы, удаление из текста лишних символов, генерация биграмм
// Что нужно: перевод букв в верхний регистр при обработке, шифровка/дешифровка, адекватный ввод/вывод

void playfairEncode() {
	vector<vector<char>> sheet = { vector<char>() }; // Таблица для кодировки
	vector<pair<char, char>> digrams; // Вектор с биграммами 
	vector<char> textToEncode; // Обработанный текст
	string text = "RAZ DVA TRI"; // Фраза для кодировки, для тестов ввод пока здесь

	textParse(text, textToEncode);
	sheetGenerator(sheet);

	bigramsGenerator(digrams, textToEncode);

	for (pair<char, char> i : digrams) {
		cout << i.first << i.second;
	}
	
}

int main() {
	playfairEncode();
}