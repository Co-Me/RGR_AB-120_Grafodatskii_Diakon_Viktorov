#include "playfair.h"
#include "gronsfeld.h"

using namespace std;

int inputOption() {
	string option = "0";

	while (option != "1" && option != "2") {
		cout << "1) Encode" << endl << "2) Decode" << endl;
		cin >> option;
	}

	return int(option[0] - '0');
}

int main() {
	int option = inputOption();
	playfair(option);
}