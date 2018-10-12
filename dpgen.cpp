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
	int pos;

	//iFile.open(fileName);
	iFile.open("C:/Users/evanj/OneDrive/SchoolWork/4Senior/574/ECE474Project2/assignment_2_circuits/474a_circuit1.txt");
	/*iFile.open("C:/Users/evanj/OneDrive/SchoolWork/4Senior/574/ECE474Project2/assignment_2_circuits/474a_circuit2.txt");
	iFile.open("C:/Users/evanj/OneDrive/SchoolWork/4Senior/574/ECE474Project2/assignment_2_circuits/474a_circuit3.txt");
	iFile.open("C:/Users/evanj/OneDrive/SchoolWork/4Senior/574/ECE474Project2/assignment_2_circuits/474a_circuit4.txt");
	iFile.open("C:/Users/evanj/OneDrive/SchoolWork/4Senior/574/ECE474Project2/assignment_2_circuits/574a_circuit5.txt");
	iFile.open("C:/Users/evanj/OneDrive/SchoolWork/4Senior/574/ECE474Project2/assignment_2_circuits/574a_circuit6.txt");*/

	if (iFile.is_open()) {
		while (!iFile.eof()) {
			//Read first keyword to check type
			getline(iFile, line);

			if (line.find("=") == string::npos && !line.empty()) {
				istringstream lineStream(line);
				lineStream >> currType >> bitWidth;
				getline(lineStream, varNames);
				varNames = varNames.substr(1, varNames.length() - 1);

				size_t begin = bitWidth.find_first_of("01234456789");

				while ((pos = varNames.find(delimiter)) != string::npos) {
					tempVar.setVarType(currType);
					tempVar.setBitWidth(stoi(bitWidth.substr(begin, bitWidth.length() - 1)));

					currName = varNames.substr(0, pos);
					varNames.erase(0, pos + delimiter.length());
					tempVar.setName(currName);

					varList.push_back(tempVar);
				}

				if (!varNames.empty()) {
					tempVar.setVarType(currType);
					tempVar.setBitWidth(stoi(bitWidth.substr(begin, bitWidth.length() - 1)));
					tempVar.setName(varNames);
					varList.push_back(tempVar);
				}
			}
			else if (line.find("=") != string::npos) {
				//PARSE OPERATORS
			}
		}
	}

	for (auto i : varList) {
		i.toString();
	}

	return varList;
}

int main(int argc, char *argv[]) {

	//Step 1: Read file input line by line
	vector<Variable> vars = getVars("balls");

	//Convert to Verilog line of code and export to .v
	return 0;
}
