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
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {

	//Step 1: Read file input line by line
	ifstream iFile;
	string line;
	string fileText;

	iFile.open("C:/Users/evanj/OneDrive/SchoolWork/4Senior/574/ECE474Project2/assignment_2_circuits/474a_circuit1.txt");

	if (iFile.is_open()) {
		while (!iFile.eof()) {
			//Read first keyword to check type
			getline(iFile, line);
			fileText += line + "\n";
		}
	} else return -1;

	cout << fileText;
	
	//Convert to Verilog line of code and export to .v
	return 0;
};
