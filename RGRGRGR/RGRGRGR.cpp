#include <iostream>
#include <vector>
#include <string>

using namespace std;

string codeWord = "BAKA MITAI";

void sheetGenerator(vector<vector<char>> sheet) {
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


	for (int i = 0; i < 26; i++) {
		if (!alphabet[i]) {
			sheet[rowIndex].push_back('A' + i);
			alphabet[i] = true;
		}
		if (sheet[rowIndex].size() == 5) {
			sheet.push_back(vector<char>());
			rowIndex++;
		}
	}


	for (int i = 0; i < 25; i++) {
		cout << sheet[i / 5][i % 5] << ' ';
		if ((i + 1) % 5 == 0) cout << endl;
	}

 }

int main() {
	vector<vector<char>> sheet = {vector<char>()};
	sheetGenerator(sheet);
}