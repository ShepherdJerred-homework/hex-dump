/*
Hex Dump
Jerred Shepherd

This program will take any file, and output its contents in hexidecimal, along with an ASCII preview and line numbers
*/

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

using std::fill;

using std::string;

using std::ofstream;
using std::ifstream;
using std::ios;

void printFileContents(ifstream &inputFile, string fileName) {
	int currentLine = 0;

	// https://stackoverflow.com/questions/6417817/easy-way-to-remove-extension-from-a-filename
	size_t lastindex = fileName.find_last_of(".");
	string fileNameWithoutExtension;
	if (lastindex == string::npos) {
		fileNameWithoutExtension = fileName;
	} else {
		fileNameWithoutExtension = fileName.substr(0, lastindex);
	}

	ofstream outputFile;
	outputFile.open(fileNameWithoutExtension + ".dmp", ios::out);

	outputFile << "HEX DUMP FOR FILE: " + fileName << endl << endl;

	while (inputFile.good()) {
		unsigned char buffer[16];
		fill(buffer, buffer + 16, 128);
		inputFile.read((char*)buffer, 16);

		outputFile << hex << setfill('0') << setw(8) << uppercase << currentLine << ":  ";
		for (int i = 0; i < 16; i++) {
			if (buffer[i] == 128) {
				outputFile << "  ";
			} else {
				outputFile << hex << setfill('0') << setw(2) << uppercase << (int)buffer[i];
			}
			outputFile << " ";
		}
		outputFile << " ";
		for (int i = 0; i < 16; i++) {
			unsigned char value = buffer[i];
			if (buffer[i] == 128) {
				break;
			}
			if (value >= 32 && value < 126) {
				outputFile << buffer[i];
			} else {
				outputFile << ".";
			}
		    
		}
		outputFile << endl;

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

		printFileContents(file, fileName);

		file.close();
		cout << endl << endl;
	}
}

int main() {
	run();
	system("pause");
    return 0;
}

