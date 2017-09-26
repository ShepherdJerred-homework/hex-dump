#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using std::hex;
using std::setfill;
using std::setw;
using std::uppercase;
using std::cout;
using std::cin;
using std::endl;

using std::string;

using std::ifstream;
using std::ios;

int main() {
	string fileName;

	while (true) {
		cout << "File name or e to exit: ";
		cin >> fileName;

		if (fileName == "e") {
			break;
		}

		ifstream file;
		file.open(fileName, ios::in | ios::binary);

		if (!file.is_open()) {
			cout << "Error opening file" << endl;
			continue;
		}

		cout << "HEX DUMP FOR FILE: " + fileName << endl << endl;

		int currentLine = 0;
		while (file.good() && !file.eof()) {
			unsigned char memory[16];
			file.read((char*) memory, 16);

			cout << hex << setfill('0') << setw(8) << uppercase << currentLine << ":  ";
			for (int i = 0; i < 16; i++) {
				cout << hex << setfill('0') << setw(2) << uppercase << (int)memory[i];
				cout << " ";
			}

			// for (int i = 0; i < 16; i++) {
			//     cout << memory[i];
			// }
			cout << endl;

			file.seekg(16, ios::cur);
			currentLine += 16;
		}

		file.close();
		cout << endl << endl;
	}

	system("pause");
    return 0;
}

