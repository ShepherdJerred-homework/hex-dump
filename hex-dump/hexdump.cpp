#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;

using std::string;

using std::ifstream;
using std::ios;

int main() {
	string fileName;

	do {
		cout << "File name or e to exit: ";
		cin >> fileName;

		ifstream file;
		file.open(fileName, ios::in | ios::binary);

		if (!file.is_open()) {
			cout << "Error opening file" << endl;
			continue;
		}

		int currentLine = 0;
		while (file.good() && !file.eof()) {
			char* memory = new char[16];
			file.read(memory, 16);
			cout << memory;
			file.seekg(16, ios::cur);
		}

		file.close();
		cout << endl << endl;
	} while (fileName != "e");

	system("pause");
    return 0;
}

