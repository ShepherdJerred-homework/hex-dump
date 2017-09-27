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

void printLineNumber(int currentLine) {
	cout << hex << setfill('0') << setw(8) << uppercase << currentLine << ":  ";
}

void printDumpHeader(string fileName) {
	cout << "HEX DUMP FOR FILE: " + fileName << endl << endl;
}


void printFileContents(ifstream &file) {
	int currentLine = 0;

	while (file.good()) {
		unsigned char buffer[16];
		std::fill(buffer, buffer + 16, 128);
		file.read((char*)buffer, 16);

		printLineNumber(currentLine);
		for (int i = 0; i < 16; i++) {
			if (buffer[i] == 128) {
				cout << "  ";
			} else {
				cout << hex << setfill('0') << setw(2) << uppercase << (int)buffer[i];
			}
			cout << " ";
		}
		cout << " ";
		for (int i = 0; i < 16; i++) {
			unsigned char value = buffer[i];
			if (buffer[i] == 128) {
				break;
			}
			if (value >= 32 && value < 126) {
				cout << buffer[i];
			} else {
				cout << ".";
			}
		    
		}
		cout << endl;

		currentLine += 16;
	}
}

void run() {
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

		printDumpHeader(fileName);
		printFileContents(file);

		file.close();
		cout << endl << endl;
	}
}

int main() {
	run();
	system("pause");
    return 0;
}

