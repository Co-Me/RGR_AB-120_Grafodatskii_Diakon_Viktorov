#include <iostream>;
#include "inpout.h"
#include "playfair.h"
#include "gronsfeld.h"

using namespace std;
using namespace N;

void writeMenu() {
	cout << "0) Exit" << endl;
	cout << "1) Gronsfeld cipher" << endl;
	cout << "2) Playfair cipher" << endl;
}

void menu() {
	Inpout io;
	Grons gf;
	Playf pf;
	io.clear();

	int choice;

	while (true) {
		writeMenu();
		cin >> choice;
		int option;
		string plaintext;
		string key = "";
		switch (choice) {
			case 0:
				cout << "Good Bye!";
				return;
			case 1:
				option = io.readOption();
				plaintext = io.readInput();
				key = io.readKey();
				gf.gronsfeldCipher(option, plaintext, key);
				break;
			case 2:
				option = io.readOption();
				plaintext = io.readInput();
				key = io.readKey();
				pf.playfairCipher(option, plaintext, key);
				break;
			default:
				break;
		}
	}
}

int main() {
	menu();
}