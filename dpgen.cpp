/*
Name: Brendan Cassidy, Diego Alcantra, Evan Weiler, Logan Knott
Project: ECE 474/574 Project 2

Description: 
	This project is a parser for Behavioral netlists that will output 
	the top Module verilog file
*/

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Variable.hpp"
using namespace std;

vector<Variable> getVars(string fileName) {
	ifstream iFile;
	string line;
	string currType;
	string bitWidth;
	string varNames;
	string currName;
	string delimiter = ", ";
	vector<Variable> varList;
	Variable tempVar;
	int bit;
	int pos;

	iFile.open(fileName);

	if (iFile.is_open()) {
		while (!iFile.eof()) {
			//Read first keyword to check type
			getline(iFile, line);

			if (line.find("=") == string::npos) {
				istringstream lineStream(line);
				lineStream >> currType >> bitWidth;
				getline(lineStream, varNames);
				varNames = varNames.substr(1, varNames.length() - 1);

				size_t begin = bitWidth.find_first_of("01234456789");
				bit = stoi(bitWidth.substr(begin, bitWidth.length() - 1));

				while ((pos = varNames.find(delimiter)) != string::npos) {
					tempVar.setVarType(currType);
					tempVar.setBitWidth(bit);

					currName = varNames.substr(0, pos);
					varNames.erase(0, pos + delimiter.length());
					tempVar.setName(currName);

					varList.push_back(tempVar);
				}

				if (!varNames.empty()) {
					tempVar.setVarType(currType);
					tempVar.setBitWidth(bit);
					tempVar.setName(varNames);
					varList.push_back(tempVar);
				}
			}
			else if (line.find("=") != string::npos) {
				//PARSE OPERATORS
			}
		}
	}

	varList.resize(varList.size() - 1);

	return varList;
}

int main(int argc, char *argv[]) {

	//Step 1: Read file input line by line
	vector<Variable> vars = getVars(argv[1]);

	//Convert to Verilog line of code and export to .v
	return 0;
}
