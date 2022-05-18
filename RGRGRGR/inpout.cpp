#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>
#include <lmcons.h>
#include "inpout.h"



using namespace std;
using namespace N;

string Inpout::readInput() {
	string line;
	cout << "Write the plaintext: " << endl;
	getline(cin, line);
	getline(cin, line);

	return line;

}


void Inpout::writeOutput(string plaintext, string ciphertext, string name) {

	char username[UNLEN + 1];
	DWORD username_len = sizeof(username);
	GetUserNameA(username, &username_len);

	ofstream output("/users/" + string(username) + "/desktop/" + "output.txt", ios::app);

	output << name << endl;
	output << "Plaintext: " << plaintext << endl;
	output << "Ciphertext: " << ciphertext << endl << endl << endl;

	output.close();
	cout << "Output file has been updated" << endl << endl;
}

int Inpout::readOption() {
	string option = "0";

	while (option != "1" && option != "2") {
		cout << "1) Encode" << endl << "2) Decode" << endl;
		cin >> option;
	}

	return int(option[0] - '0');
}

void Inpout::clear() {
	char username[UNLEN + 1];
	DWORD username_len = sizeof(username);
	GetUserNameA(username, &username_len);

	ofstream output("/users/" + string(username) + "/desktop/" + "output.txt");
	output.clear();
	output.close();
}

string Inpout::readKey() {
	string key;
	cout << "Key: " << endl;
	getline(cin, key);
	return key;
}