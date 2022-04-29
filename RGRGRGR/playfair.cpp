/*
Шифр Плейфера использует таблицу для шифровки. В таблицу 5х5 в любом порядке записываются все уникальные буквы кодовой фразы, в данном случае, заполняются поочередно строки.
В оставшиеся ячейки записываются по порядку остальные буквы алфавита (I и J считаются за I). Исходный текст разбивается на биграммы,
если две буквы в биграмме одинаковые, то между ними записывается X или Q. Далее преобразование происходит по правилам:
1. Буквы в одной строке - заменить на буквы, стоящие справа.
2. Буквы в одном столбце - заменить на буквы, стоящие снизу.
3. Буквы не в столбце и не в строке - заменить на буквы, стоящие в этих же строках, но на других углах прямоугольника.
Таблица циклична, при дешифровке правила инвертируются.
*/
#include <iostream>
#include <vector>
#include <string>
#include "playfair.h"

using namespace std;

#define ENCODE 1
#define DECODE 2

vector<string> sheetGenerator(string codePhrase) { // Генерация таблицы для шифрования
	vector<string> sheet = {""};
	string phrase = textParse(codePhrase);
	int rowIndex = 0;
	bool alphabet[26] = { false };
	alphabet['J' - 'A'] = true; // Буквы I и J считать за I для уменьшения алфавита

	for (char i : phrase) {
		if (!alphabet[i - 'A']) {
			sheet[rowIndex].push_back(i);
			alphabet[i - 'A'] = true;
		}

		if (sheet[rowIndex].size() == 5) {
			sheet.push_back("");
			rowIndex++;
		}
	}

	for (int i = 0; i < 26; i++) {
		if (!alphabet[i]) {
			sheet[rowIndex].push_back('A' + i);
			alphabet[i] = true;
		}
		if (sheet[rowIndex].size() == 5) {
			sheet.push_back("");
			rowIndex++;
		}
	}

	for (int i = 0; i < 25; i++) {
		cout << sheet[i / 5][i % 5] << ' ';
		if ((i + 1) % 5 == 0) cout << endl;
	}

	return sheet;

}


vector<pair<char, char>> bigramsGenerator(string textToEncode) { // Генератор вектора биграмм
	vector<pair<char, char>> bigrams;
	size_t n = textToEncode.size();

	for (size_t i = 0; i < n; i += 2) {
		bigrams.push_back(pair<char, char>(0, 0));
		bigrams.back().first = textToEncode[i];

		if (i + 1 == n) {
			break;
		}

		if (textToEncode[i] == textToEncode[i + 1]) {
			if (textToEncode[i] == 'X') {
				bigrams.back().second = 'Q';
			}
			else {
				bigrams.back().second = 'X';
			}
			i--;
			continue;
		}

		bigrams.back().second = textToEncode[i + 1];
	}

	if (bigrams.back().second == 0) {
		if (bigrams.back().first == 'X') {
			bigrams.back().second = 'Q';
		}
		else {
			bigrams.back().second = 'X';
		}
	}

	return bigrams;
}


string textParse(string text) { // Обработка исходного текста, удаление лишних символов, замена J на I, перевод в верхний регистр
	string parsedText;

	for (char i : text) {

		if (i >= 'a' && i <= 'z') {
			i += 'A' - 'a';
		}

		if (i >= 'A' && i <= 'Z') {
			if (i == 'J') {
				i = 'I';
			}
			parsedText.push_back(i);
		}
	}

	return parsedText;
}

pair<pair<int, int>, pair<int, int>> findPositions(pair<char, char> bigram, vector<string> sheet) { // Нахождение позиций символов биграммы в таблице
	pair<pair<int, int>, pair<int, int>> positions;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (sheet[i][j] == bigram.first) {
				positions.first.first = i;
				positions.first.second = j;
			}

			if (sheet[i][j] == bigram.second) {
				positions.second.first = i;
				positions.second.second = j;
			}
		}
	}

	return positions;
}

int chooseRule(pair<pair<int, int>, pair<int, int>> positions) { // Выбор правила преобразования на основе позиций символов биграммы
	int row1 = positions.first.first, col1 = positions.first.second;
	int row2 = positions.second.first, col2 = positions.second.second;
	int rule = 0;

	if (row1 == row2) {
		rule = 1;
	}
	else if (col1 == col2) {
		rule = 2;
	}
	else {
		rule = 3;
	}

	return rule;
}

pair<char, char> bigramTransform(pair<char, char> bigram, vector<string> sheet, pair<pair<int, int>, pair<int, int>> positions, int option) { // Преобразование символов биграммы
	int rule = chooseRule(positions);
	int row1 = positions.first.first, col1 = positions.first.second;
	int row2 = positions.second.first, col2 = positions.second.second;
	int move = 0;

	if (option == ENCODE) {
		move = 1;
	}
	else if (option == DECODE) {
		move = 4;
	}

	if (rule == 1) {
		bigram.first = sheet[row1][(col1 + move) % 5];
		bigram.second = sheet[row2][(col2 + move) % 5];
	}
	else if (rule == 2) {
		bigram.first = sheet[(row1 + move) % 5][col1];
		bigram.second = sheet[(row2 + move) % 5][col2];
	}
	else if (rule == 3) {
		bigram.first = sheet[row1][col2];
		bigram.second = sheet[row2][col1];
	}

	return bigram;
}


void playfair(int option) {
	vector<string> sheet; // Таблица для кодировки
	vector<pair<char, char>> bigrams, encodedBigrams; // Векторы с биграммами 
	string textToEncode; // Обработанный текст
	string codePhrase = "NSTUNETI"; // Кодовое слово
	string text;

	cout << "Text: ";
	getline(cin, text);
	getline(cin, text);

	sheet = sheetGenerator(codePhrase);
	textToEncode = textParse(text);
	bigrams = bigramsGenerator(textToEncode);


	for (pair<char, char> bigram : bigrams) {
		encodedBigrams.push_back(bigramTransform(bigram, sheet, findPositions(bigram, sheet), option));
	}

	for (pair<char, char> i : encodedBigrams) {
		cout << i.first << i.second;
	}

}