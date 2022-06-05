#include <fstream>
#include <iostream>
#include <string>
#include <random>
#include <Windows.h>
#include <lmcons.h>
#include "inpout.h"

using namespace std;
using namespace N;

#define ENCODE 1
#define DECODE 2


string Inpout::readInput() {
	string line;
	cout << "Write the text: " << endl;
	getline(cin, line);
	getline(cin, line);

	return line;

}

void Inpout::writeOutput(string starttext, string endtext, string name, int option, string key) {

	ofstream output("output.txt", ios::app);

	output << name << endl;

	if (option == ENCODE) {
		output << "Plaintext: " << starttext << endl;
		output << "Key: " << key << endl;
		output << "Ciphertext: " << endtext << endl << endl << endl;
	}
	if (option == DECODE) {
		output << "Ciphertext: " << starttext << endl;
		output << "Key: " << key << endl;
		output << "Plaintext: " << endtext << endl << endl << endl;
	}

	output.close();
	cout << endl << "Output file has been updated" << endl << endl;
}

int Inpout::readOption(string type) {
	string option = "0";

	if (type == "Option") {
		cout << "1) Encode" << endl << "2) Decode" << endl;
	}
	else if (type == "Gen") {
		cout << "1) Type input via console" << endl << "2) Generate input randomly" << endl;
	}
	cin >> option;

	while (option != "1" && option != "2") {
		if (type == "Option") {
			cout << endl << "Incorrect choice" << endl << endl << "1) Encode" << endl << "2) Decode" << endl;
		}
		else if (type == "Gen") {
			cout << endl << "Incorrect choice" << endl << endl << "1) Type input via console" << endl << "2) Generate input randomly" << endl;
		}
		cout << endl;
		cin >> option;
	}

	return int(option[0] - '0');
}

void Inpout::clear() {
	ofstream output("output.txt");
	output.clear();
	output.close();
}

string Inpout::readKey() {
	string key;
	cout << "Key: " << endl;
	getline(cin, key);
	return key;
}

bool Inpout::checkText(string text, string option) {
	if (option == "Gronsfeld" || option == "Skital") {
		for (char i : text) {
			if (!(i >= '0' && i <= '9')) {
				return false;
			}
		}
		return true;
	}

	for (char i : text) {
		if (i != ' ' && !(i >= 'a' && i <= 'z') && !(i >= 'A' && i <= 'Z')) {
			return false;
		}
	}
	return true;
}

string Inpout::generateInput(int len, string name) {
	srand(time(NULL));
	string alp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string text = "";

	if (name == "Gronsfeld" || name == "Skital") {
		text += '1' + rand() % 9;
		for (int i = 1; i < len; ++i) {
			text += '0' + rand() % 10;
		}
		return text;
	}

	while (text.size() <= len) {
		text += textParse(dict[rand() % dict.size()]) + ' ';
	}
	return text;
}

string Inpout::textParse(string text) {
	string parsedText = "";

	for (char i : text) {
		i = toupper(i);
		parsedText.push_back(i);
	}

	return parsedText;
}

bool Inpout::pass() {
	string password;
	cout << endl << "Password: ";
	cin >> password;
	if (password == correct) return true;
	return false;
}