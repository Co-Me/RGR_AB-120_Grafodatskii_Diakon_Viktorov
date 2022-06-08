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


string Inpout::readText() {
	string line;
	cout << "Text: ";
	getline(cin, line);

	return line;
}

int Inpout::countLines() {
	int n = 0;
	string line;
	ifstream myfile("keys.txt");

	while (getline(myfile, line))
		++n;
	return n;
}

void Inpout::writeOutput(string starttext, string endtext, string name, int option, string key) {

	int n = countLines() + 1;

	ofstream output("output.txt", ios::app);

	output << n << ") " << name << endl;

	if (option == ENCODE) {
		output << "Plaintext: " << starttext << endl;
		output << "Ciphertext: " << endtext << endl << endl;
	}
	if (option == DECODE) {
		output << "Ciphertext: " << starttext << endl;
		output << "Plaintext: " << endtext << endl << endl;
	}

	output.close();
	cout << "Output file has been updated" << endl;

	output.open("keys.txt", ios::app);
	output << n << ") " << name << ": " << key << endl;
	output.close();

}

void Inpout::clear() {
	ofstream output("output.txt");
	output.clear();
	output.close();

	output.open("keys.txt");
	output.clear();
	output.close();
	cout << "The contents of output.txt have been deleted" << endl;

}

string Inpout::readKey() {
	string key;
	cout << "Key: ";
	getline(cin, key);
	return key;
}

bool Inpout::checkText(string text, string option) {
	string alp = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!?,.;:(){}<>'\"\n/0123456789 ";
	if (text.size() == 0) return false;
	if (option == "Gronsfeld" || option == "Scytale") {
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

	if (name == "Gronsfeld" || name == "Scytale") {
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

bool Inpout::pass() {
	string password;
	cout << endl << "Password: ";
	getline(cin, password);
	if (password == Inpout::correct) return true;
	return false;
}

pair<string, string> Inpout::readFile(bool key) {
	string text = "";
	string line;
	string path;
	pair <string, string> inp("", "");

	cout << "Path to input file: ";
	getline(cin, path);

	ifstream f(path);
	if (!f.good()) throw string("Incorrect path");
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
		if (!f.eof()) text += '\n';
	}
	inp.first = text;
	f.close();
	return inp;
}


void Inpout::print() {
	cout << "Contents of the output.txt: " << endl;

	ifstream f("output.txt");

	string line;
	while (!f.eof()) {
		getline(f, line);
		cout << line << endl;
	}
	f.close();
}