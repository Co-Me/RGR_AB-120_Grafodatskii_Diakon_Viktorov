#include <iostream>
#include <fstream>

#include "menu.h"

using namespace std;
using namespace N;

void print() {
	cout << "Contents of the output.txt: " << endl;

	ifstream f("readme.txt");

	string line;
	while (!f.eof()) {
		getline(f, line);
		cout << line << endl;
	}
	f.close();
}

int main() {
	srand(time(NULL));
	Menu mn;
	//print();
	mn.main();
}