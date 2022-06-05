/*Файл с выводом создается в дикертории проекта
*/


#include <iostream>
#include <fstream>
#include <Windows.h>
#include "inpout.h"
#include "playfair.h"
#include "gronsfeld.h"
#include "cezar.h"
#include "viginer.h"
#include "atbash.h"
#include "skital.h"

using namespace std;
using namespace N;

void writeMenu() {
	cout << "0) Exit and see the output" << endl;
	cout << "1) Gronsfeld cipher *(only numbers as a key)" << endl;
	cout << "2) Playfair cipher" << endl;
	cout << "3) Skital *(core diameter as a key)" << endl;
	cout << "4) Cezar" << endl;
	cout << "5) Viginer" << endl;
	cout << "6) Atbash" << endl;
	cout << "7) Generate inputs for all ciphers" << endl;
	
	cout << endl;
}

void menu() {
	Inpout io;
	Grons gf;
	Playf pf;
	Cezar cz;
	Viginer vg;
	Atbash ab;
	Skital sk;
	io.clear();

	string choice;

	while (true) {
		try {
			writeMenu();
			cin >> choice;
			if (choice.size() > 1) throw string("Incorrect choice");
			int option, inpoption;
			string text;
			string key = "";
			string result;
			string filename = " ";
			pair<string, string> finp;

			switch (choice[0]) {
			case '0':
				cout << "Good Bye!";
				system("notepad output.txt");
				return;

			case '1':
				option = io.readOption("Option");
				inpoption = io.readOption("Inp");
				if (inpoption == 1) {
					text = io.readInput();
					key = io.readKey();
				}
				else if (inpoption == 2) {
					text = io.generateInput(30);
					key = io.generateInput(6, "Gronsfeld");
				}
				else {
					cout << "Last line will be used as a key" << endl;
					system("notepad input.txt");
					finp = io.readFile("input.txt", 1);
					text = finp.first;
					key = finp.second;
				}
				if (!io.checkText(text)) throw string ("Incorrect text");
				if (!io.checkText(key, "Gronsfeld")) throw string("Incorrect key");
				if (!io.pass()) throw string("Inncorect password");
				gf.gronsfeldCipher(option, text, key);
				break;

			case '2':
				option = io.readOption("Option");
				inpoption = io.readOption("Inp");
				if (inpoption == 1) {
					text = io.readInput();
					key = io.readKey();
				}
				else if (inpoption == 2) {
					text = io.generateInput(30);
					key = io.generateInput(6);
				}
				else {
					cout << "Last line will be used as a key" << endl;
					system("notepad input.txt");
					finp = io.readFile("input.txt", 1);
					text = finp.first;
					key = finp.second;
				}
				if (!io.checkText(text)) throw string ("Incorrect text");
				if (!io.checkText(key)) throw string ("Incorrect key");
				if (!io.pass()) throw string("Inncorect password");
				pf.playfairCipher(option, text, key);
				break;

			case '3':
				option = io.readOption("Option");
				inpoption = io.readOption("Inp");
				if (inpoption == 1) {
					text = io.readInput();
					key = io.readKey();
				}
				else if (inpoption == 2) {
					text = io.generateInput(30);
					key = io.generateInput(1, "Skital");
				}
				else {
					cout << "Last line will be used as a key" << endl;
					system("notepad input.txt");
					finp = io.readFile("input.txt", 1);
					text = finp.first;
					key = finp.second;
				}
				if (!io.checkText(text)) throw string("Incorrect text");
				if (!io.checkText(key, "Skital")) throw string("Incorrect key");
				if (!io.pass()) throw string("Inncorect password");
				sk.skital(option, text, key);
				break;

			case '4':
				option = io.readOption("Option");
				inpoption = io.readOption("Inp");
				if (inpoption == 1) {
					text = io.readInput();
				}
				else if (inpoption == 2) {
					text = io.generateInput(30);
				}
				else {
					system("notepad input.txt");
					finp = io.readFile("input.txt", 1);
					text = finp.first;
					key = finp.second;
				}
				if (!io.checkText(text)) throw string("Incorrect text");
				if (!io.pass()) throw string("Inncorect password");
				if (option == 1) cz.cezar(text);
				else if (option == 2) cz.decezar(text);
				break;

			case '5':
				option = io.readOption("Option");
				inpoption = io.readOption("Inp");
				if (inpoption == 1) {
					text = io.readInput();
					key = io.readKey();
				}
				else if (inpoption == 2) {
					text = io.generateInput(30);
					key = io.generateInput(6);
				}
				else {
					cout << "Last line will be used as a key" << endl;
					system("notepad input.txt");
					finp = io.readFile("input.txt", 1);
					text = finp.first;
					key = finp.second;
				}
				if (!io.checkText(text)) throw string("Incorrect text");
				if (!io.checkText(key)) throw string("Incorrect key");
				if (!io.pass()) throw string("Inncorect password");
				if (option == 1) vg.viginer(text, key);
				else if (option == 2) vg.deviginer(text, key);
				break;

			case '6':
				option = io.readOption("Option");
				inpoption = io.readOption("Inp");

				if (inpoption == 1) {
					text = io.readInput();
				}
				else if (inpoption == 2) {
					text = io.generateInput(30);
				}
				else {
					system("notepad input.txt");
					finp = io.readFile("input.txt", 1);
					text = finp.first;
					key = finp.second;
				}
				if (!io.checkText(key)) throw string("Incorrect key");
				if (!io.pass()) throw string("Inncorect password");
				if (option == 1) ab.encode_atbash(text);
				else if (option == 2) ab.decode_atbash(text);
				break;

			case '7':
				if (!io.pass()) throw string("Inncorect password");
				text = io.generateInput(30);
				key = io.generateInput(6, "Gronsfeld");
				result = gf.gronsfeldCipher(1, text, key);
				gf.gronsfeldCipher(2, result, key);


				key = io.generateInput(6);
				result = pf.playfairCipher(1, text, key);
				pf.playfairCipher(2, result, key);


				key = io.generateInput(1, "Skital");
				result = sk.skital(1, text, key);
				sk.skital(2, result, key);


				result = cz.cezar(text);
				cz.decezar(result);


				key = io.generateInput(6);
				result = vg.viginer(text, key);
				vg.deviginer(result, key);


				result = ab.encode_atbash(text);
				ab.decode_atbash(result);
				break;

			default:
				throw string("Incorrect choice");
				break;
			}
		}
		catch (string error) {
			cout << endl << error << endl;
			cout << endl;
		}
	}
}

int main() {
	srand(time(NULL));
	menu();
}