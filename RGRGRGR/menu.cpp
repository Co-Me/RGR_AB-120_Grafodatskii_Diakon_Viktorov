#include <algorithm>
#include <iostream>
#include <fstream>
#include "inpout.h"
#include "playfair.h"
#include "gronsfeld.h"
#include "caesar.h"
#include "viginere.h"
#include "atbash.h"
#include "scytale.h"
#include "menu.h"

using namespace std;
using namespace N;

Inpout io;
Grons grns;
Playf plf;
Caesar csr;
Viginere vgn;
Atbash atb;
Scytale sct;

void Menu::help() {
	cout << "Common:" << endl;
	cout << "HELP		Show this menu." << endl;
	cout << "EXIT		Quit the program." << endl;
	cout << "BACK		Return to the previous menu." << endl;
	cout << "CLR		Clear the output.txt file." << endl;
	cout << "CLS		Clear the console." << endl;
	cout << "PRINT		Show the contents of an output file." << endl;

	cout << endl << "Ciphers:" << endl;
	cout << "GRONSFELD	Use a Gronsfeld cipher." << endl;
	cout << "PLAYFAIR	Use a Playfair cipher." << endl;
	cout << "SCYTALE		Use a Scytale cipher." << endl;
	cout << "CAESAR		Use a Caesar cipher." << endl;
	cout << "VIGINERE	Use a Vigenere cipher." << endl;
	cout << "ATBASH		Use an Atbash cipher." << endl;
	cout << "FASTCHECK	Generate random input and use every cipher with it." << endl;

	cout << endl << "How to enter input:" << endl;
	cout << "CONSOLE		Enter input via console." << endl;
	cout << "FILE		Read input from file." << endl;
	cout << "RANDOM		Generate input randomly." << endl;

	cout << endl << "What to do with the input:" << endl;
	cout << "ENCODE		Encode the text." << endl;
	cout << "DECODE		Decode the text." << endl;

}

Menu::Command Menu::identifyCommand(string command) {
	transform(command.begin(), command.end(), command.begin(), ::toupper);
	if (command == "HELP") return Menu::Command::HELP;
	if (command == "EXIT") return Menu::Command::EXIT;
	if (command == "BACK") return Menu::Command::BACK;
	if (command == "CLR") return Menu::Command::CLR;
	if (command == "CLS") return Menu::Command::CLS;
	if (command == "PRINT") return Menu::Command::PRINT;

	if (command == "GRONSFELD") return Menu::Command::GRONSFELD;
	if (command == "PLAYFAIR") return Menu::Command::PLAYFAIR;
	if (command == "SCYTALE") return Menu::Command::SCYTALE;
	if (command == "CAESAR") return Menu::Command::CAESAR;
	if (command == "VIGINERE") return Menu::Command::VIGINERE;
	if (command == "ATBASH") return Menu::Command::ATBASH;
	if (command == "FASTCHECK") return Menu::Command::FASTCHECK;

	if (command == "CONSOLE") return Menu::Command::CONSOLE;
	if (command == "FILE") return Menu::Command::FILE;
	if (command == "RANDOM") return Menu::Command::RANDOM;

	if (command == "ENCODE") return Menu::Command::ENCODE;
	if (command == "DECODE") return Menu::Command::DECODE;

	return Menu::Command::INCORRECT;
}

void Menu::main() {
	help();

	while (true) {
		string line;
		Command command;
		cout << endl << "Main> ";
		getline(cin, line);

		command = identifyCommand(line);

		switch (command) {
		case Command::HELP:
			help();
			break;

		case Command::EXIT:
			cout << "Good bye!" << endl;
			exit(0);

		case Command::CLS:
			system("cls");
			break;

		case Command::GRONSFELD:
			cipher(command, "Gronsfeld");
			break;

		case Command::PLAYFAIR:
			cipher(command, "Playfair");
			break;

		case Command::SCYTALE:
			cipher(command, "Scytale");
			break;

		case Command::CAESAR:
			cipher(command, "Caesar");
			break;

		case Command::VIGINERE:
			cipher(command, "Viginere");
			break;

		case Command::ATBASH:
			cipher(command, "Atbash");
			break;

		case Command::FASTCHECK:
			try {
				fastcheck();
			}
			catch (string error) {
				cout << error << endl;
			}
			break;

		case Command::CLR:
			io.clear();
			break;

		case Command::PRINT:
			io.print();
			break;

		default:
			cout << "There is no such command, or you can't use it in this menu." << endl;
			cout << "Use HELP to see the list of available commands." << endl;
			break;
		}
	}
}

void Menu::cipher(Command cipher, string cipherName) {
	while (true) {
		string line;
		Menu::Command command;
		cout << endl << "Main\\" << cipherName << ">";
		getline(cin, line);

		command = identifyCommand(line);

		switch (command) {
		case Command::HELP:
			help();
			break;

		case Command::EXIT:
			cout << "Good bye!" << endl;
			exit(0);

		case Command::CLS:
			system("cls");
			break;

		case Command::CONSOLE:
			inp(cipher, command, cipherName, "Console");
			break;

		case Command::FILE:
			inp(cipher, command, cipherName, "File");
			break;

		case Command::RANDOM:
			inp(cipher, command, cipherName, "Random");
			break;

		case Command::BACK:
			return;

		case Command::CLR:
			io.clear();
			break;

		case Command::PRINT:
			io.print();
			break;

		default:
			cout << "There is no such command, or you can't use it in this menu." << endl;
			cout << "Use HELP to see the list of available commands." << endl;
			break;
		}
	}
}

void Menu::inp(Command cipher, Command inpMode, string cipherName, string modeName) {
	while (true) {
		string line;
		Menu::Command command;
		cout << endl << "Main\\" << cipherName << "\\" << modeName << ">";
		getline(cin, line);

		command = identifyCommand(line);
		try {
			switch (command) {
			case Command::HELP:
				help();
				break;

			case Command::EXIT:
				cout << "Good bye!" << endl;
				exit(0);

			case Command::CLS:
				system("cls");
				break;

			case Command::ENCODE:
				type(cipher, inpMode, command);
				break;

			case Command::DECODE:
				type(cipher, inpMode, command);
				break;

			case Command::BACK:
				return;

			case Command::CLR:
				io.clear();
				break;

			case Command::PRINT:
				io.print();
				break;

			default:
				cout << "There is no such command, or you can't use it in this menu." << endl;
				cout << "Use HELP to see the list of available commands." << endl;
				break;
			}
		}
		catch (string error) {
			cout << error << endl;
		}
	}
}

void Menu::type(Command cipher, Command inpMode, Command codeMode) {
	string text;
	string key;
	pair<string, string> fromFile;
	while (true) {
		if (!io.pass()) throw string("Incorrect password!");
		switch (cipher) {
		case Command::GRONSFELD:
			switch (inpMode) {
				case Command::CONSOLE:
					text = io.readText();
					key = io.readKey();
					break;

				case Command::FILE:
					fromFile = io.readFile(true);
					text = fromFile.first;
					key = fromFile.second;
					break;

				case Command::RANDOM:
					text = io.generateInput(30);
					key = io.generateInput(6, "Gronsfeld");
					break;
			}
			if (!io.checkText(text)) throw string("Incorrect text");
			if (!io.checkText(key, "Gronsfeld")) throw string("Incorrect key, key must consist of numbers");

			if (codeMode == Command::ENCODE) grns.gronsfeldCipher(1, text, key);
			else if (codeMode == Command::DECODE) grns.gronsfeldCipher(2, text, key);
			return;

		case Command::PLAYFAIR:
			switch (inpMode) {
			case Command::CONSOLE:
				text = io.readText();
				key = io.readKey();
				break;

			case Command::FILE:
				fromFile = io.readFile(true);
				text = fromFile.first;
				key = fromFile.second;
				break;

			case Command::RANDOM:
				text = io.generateInput(30);
				key = io.generateInput(6);
				break;
			}
			if (!io.checkText(text)) throw string("Incorrect text");
			if (!io.checkText(key)) throw string("Incorrect key");

			if (codeMode == Command::ENCODE) plf.playfairCipher(1, text, key);
			else if (codeMode == Command::DECODE) plf.playfairCipher(2, text, key);
			return;

		case Command::SCYTALE:
			switch (inpMode) {
			case Command::CONSOLE:
				text = io.readText();
				key = io.readKey();
				break;

			case Command::FILE:
				fromFile = io.readFile(true);
				text = fromFile.first;
				key = fromFile.second;
				break;

			case Command::RANDOM:
				text = io.generateInput(30);
				key = io.generateInput(6, "Scytale");
				break;
			}

			if (!io.checkText(text)) throw string("Incorrect text");
			if (!io.checkText(key, "Scytale")) throw string("Incorrect key, key must consist of numbers");

			if (codeMode == Command::ENCODE) sct.scytale(1, text, key);
			else if (codeMode == Command::DECODE) sct.scytale(2, text, key);
			return;

		case Command::CAESAR:
			switch (inpMode) {
			case Command::CONSOLE:
				text = io.readText();
				break;

			case Command::FILE:
				fromFile = io.readFile(false);
				text = fromFile.first;
				break;

			case Command::RANDOM:
				text = io.generateInput(30);
				break;
			}
			if (!io.checkText(text)) throw string("Incorrect text");

			if (codeMode == Command::ENCODE) csr.caesar(1, text);
			else if (codeMode == Command::DECODE) csr.caesar(2, text);
			return;

		case Command::VIGINERE:
			switch (inpMode) {
			case Command::CONSOLE:
				text = io.readText();
				key = io.readKey();
				break;

			case Command::FILE:
				fromFile = io.readFile(true);
				text = fromFile.first;
				key = fromFile.second;
				break;

			case Command::RANDOM:
				text = io.generateInput(30);
				key = io.generateInput(6);
				break;
			}
			if (!io.checkText(text)) throw string("Incorrect text");
			if (!io.checkText(key)) throw string("Incorrect key");

			if (codeMode == Command::ENCODE) vgn.viginere(1, text, key);
			else if (codeMode == Command::DECODE) vgn.viginere(2, text, key);
			return;

		case Command::ATBASH:
			switch (inpMode) {
			case Command::CONSOLE:
				text = io.readText();
				break;

			case Command::FILE:
				fromFile = io.readFile(false);
				text = fromFile.first;
				break;

			case Command::RANDOM:
				text = io.generateInput(30);
				break;
			}
			if (!io.checkText(text)) throw string("Incorrect text");

			if (codeMode == Command::ENCODE) atb.atbash(1, text);
			else if (codeMode == Command::DECODE) atb.atbash(2, text);
			return;

		default:
			return;
		}
	}
}

void Menu::fastcheck() {
	string text;
	string key;
	string result;

	if (!io.pass()) throw string("Incorrect password!");

	text = io.generateInput(30);
	key = io.generateInput(6, "Gronsfeld");
	result = grns.gronsfeldCipher(1, text, key);
	grns.gronsfeldCipher(2, result, key);


	key = io.generateInput(6);
	result = plf.playfairCipher(1, text, key);
	plf.playfairCipher(2, result, key);


	key = io.generateInput(1, "Scytale");
	result = sct.scytale(1, text, key);
	sct.scytale(2, result, key);


	result = csr.caesar(1, text);
	csr.caesar(2, result);


	key = io.generateInput(6);
	result = vgn.viginere(1, text, key);
	vgn.viginere(2, result, key);


	result = atb.atbash(1, text);
	atb.atbash(2, result);
}