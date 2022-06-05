#include <fstream>
#include <iostream>
#include <string>
#include <random>
#include <Windows.h>
#include <algorithm>
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
		cin >> option;
		if (option == "1" || option == "2")  return stoi(option);
	}
	else if (type == "Inp") {
		cout << "1) Type input via console" << endl << "2) Generate input randomly" << endl << "3) Read from the file" << endl;
		cin >> option;
		if (option == "1" || option == "2" || option == "3")  return stoi(option);
	}

	while (true) {
		if (type == "Option") {
			cout << endl << "Incorrect choice" << endl << endl << "1) Encode" << endl << "2) Decode" << endl;
			cin >> option;
			if (option == "1" || option == "2") return stoi(option);
		}
		else if (type == "Inp") {
			cout << endl << "Incorrect choice" << endl << endl << "1) Type input via console" << endl << "2) Generate input randomly" << endl << "3) Read from the file" << endl;
			cin >> option;
			if (option == "1" || option == "2" || option == "3")  return stoi(option);
		}
	}
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
	string alp = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!?,.;:(){}<>'\"/0123456789 ";
	if (text.size() == 0) return false;
	if (option == "Gronsfeld" || option == "Skital") {
		for (char i : text) {
			if (!(i >= '0' && i <= '9')) {
				return false;
			}
		}
		return true;
	}
	if (all_of(text.begin(), text.end(), [alp](char a) {return alp.find(a) != SIZE_MAX; })) return true;
	else return false;
}

string Inpout::generateInput(int len, string name) {
	string signs = "!?,.;:(){}<>'\"0123456789 ";
	string text = "";

	if (name == "Gronsfeld" || name == "Skital") {
		text += '1' + rand() % 9;
		for (int i = 1; i < len; ++i) {
			text += '0' + rand() % 10;
		}
		return text;
	}

	string word;
	while (text.size() <= len) {
		word = dict[rand() % dict.size()];
		for (char& c : word) {
			if (rand() % 2 == 0) c = toupper(c);
		}
		text += word + signs[rand() % signs.size()];
		if (*(text.end() - 1) != ' ') text += ' ';
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

pair<string, string> Inpout::readFile(string name, bool key) {
	string text = "";
	string line;
	pair <string, string> inp("", "");

	ifstream f(name);
	if (f.eof()) {
		return inp;
	}
	while (true) {
		f >> line;
		if (f.eof()) {
			if (key) inp.second = line;
			else text += line;
			break;
		}
		text += line;
	}
	inp.first = text;
	return inp;
}