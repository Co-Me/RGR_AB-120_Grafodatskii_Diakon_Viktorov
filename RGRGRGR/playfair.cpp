/*
���� �������� ���������� ������� ��� ��������. � ������� 5�5 � ����� ������� ������������ ��� ���������� ����� ������� �����, � ������ ������, ����������� ���������� ������.
� ���������� ������ ������������ �� ������� ��������� ����� �������� (I � J ��������� �� I). �������� ����� ����������� �� ��������,
���� ��� ����� � �������� ����������, �� ����� ���� ������������ X ��� Q. ����� �������������� ���������� �� ��������:
1. ����� � ����� ������ - �������� �� �����, ������� ������.
2. ����� � ����� ������� - �������� �� �����, ������� �����.
3. ����� �� � ������� � �� � ������ - �������� �� �����, ������� � ���� �� �������, �� �� ������ ����� ��������������.
������� ��������, ��� ���������� ������� �������������.
*/
#include <iostream>
#include <vector>
#include <string>
#include "playfair.h"
#include "inpout.h"

using namespace std;
using namespace N;

#define ENCODE 1
#define DECODE 2

vector<string> Playf::sheetGenerator(string codePhrase) { // ��������� ������� ��� ����������
	vector<string> sheet = {""};
	string phrase = textParse(codePhrase);
	int rowIndex = 0;
	bool alphabet[26] = { false };
	alphabet['J' - 'A'] = true; // ����� I � J ������� �� I ��� ���������� ��������

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

	return sheet;

}


vector<pair<char, char>> Playf::bigramsGenerator(string textToEncode) { // ��������� ������� �������
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


string Playf::textParse(string text) { // ��������� ��������� ������, �������� ������ ��������, ������ J �� I, ������� � ������� �������
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

pair<pair<int, int>, pair<int, int>> Playf::findPositions(pair<char, char> bigram, vector<string> sheet) { // ���������� ������� �������� �������� � �������
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

int Playf::chooseRule(pair<pair<int, int>, pair<int, int>> positions) { // ����� ������� �������������� �� ������ ������� �������� ��������
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

pair<char, char> Playf::bigramTransform(pair<char, char> bigram, vector<string> sheet, pair<pair<int, int>, pair<int, int>> positions, int option) { // �������������� �������� ��������
	int rule = Playf::chooseRule(positions);
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


void Playf::playfairCipher(int option, string plaintext, string key) {
	Inpout io;

	vector<string> sheet; // ������� ��� ���������
	vector<pair<char, char>> bigrams, encodedBigrams; // ������� � ���������� 
	string textToEncode; // ������������ �����
	string ciphertext = "";

	sheet = sheetGenerator(key);
	textToEncode = textParse(plaintext);
	bigrams = bigramsGenerator(textToEncode);


	for (pair<char, char> bigram : bigrams) {
		encodedBigrams.push_back(bigramTransform(bigram, sheet, findPositions(bigram, sheet), option));
	}

	for (pair<char, char> i : encodedBigrams) {
		ciphertext.push_back(i.first);
		ciphertext.push_back(i.second);

	}

	io.writeOutput(plaintext, ciphertext, "Playfair cipher");

}