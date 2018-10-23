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
#include <sstream>
#include "Variable.hpp"

using namespace std;

string callOperator(vector<Variable> variables, string operand, int num) {
	string toReturn;
	if (operand.compare("=") == 0) {	//REG
		toReturn = "REG reg" + std::to_string(num) + "(" + variables.at(1).getName() + ", " + variables.at(0).getName() + ");\n";
	}
	else if (operand.compare("+") == 0)	{ //ADD
		toReturn = "ADD add" + std::to_string(num) + "(" + variables.at(1).getName() + ", " + variables.at(2).getName() + ", " + variables.at(0).getName() + ");\n";
	}
	else if (operand.compare("-") == 0) {	//SUB
		toReturn = "SUB sub" + std::to_string(num) + "(" + variables.at(1).getName() + ", " + variables.at(2).getName() + ", " + variables.at(0).getName() + ");\n";
	}
	else if (operand.compare("*") == 0) {	//MUL
		toReturn = "MUL mul" + std::to_string(num) + "(" + variables.at(1).getName() + ", " + variables.at(2).getName() + ", " + variables.at(0).getName() + ");\n";
	}
	else if (operand.compare(">") == 0) {	//COMP (gt output)
		toReturn = "COMP comp" + to_string(num) + "(" + variables.at(1).getName() + ", " + variables.at(2).getName() + ", " + variables.at(0).getName() + ", 0, 0);\n";
	}
	else if (operand.compare("<") == 0) {	//COMP (lt output)
		toReturn = "COMP comp" + to_string(num) + "(" + variables.at(1).getName() + ", " + variables.at(2).getName() + ", 0, " + variables.at(0).getName() + ", 0);\n";
	}
	else if (operand.compare("==") == 0) {	//COMP (eq output)
		toReturn = "COMP comp" + to_string(num) + "(" + variables.at(1).getName() + ", " + variables.at(2).getName() + ", 0, 0, " + variables.at(0).getName() + ");\n";
	}
	else if (operand.compare("?") == 0) {	//MUX2x1
		toReturn = "MUX2x1 mux" + to_string(num) + "(" + variables.at(2).getName() + ", " + variables.at(3).getName() + ", " + variables.at(1).getName() + ", " + variables.at(0).getName() + ");\n";
	}
	else if (operand.compare(">>")== 0) {	//SHR
		toReturn = "SHR shr" + to_string(num) + "(" + variables.at(1).getName() + "," + variables.at(2).getName() + "," + variables.at(0).getName() + ");\n";
	}
	else if (operand.compare("<<")== 0) {	//SHL
		toReturn = "SHL shl" + to_string(num) + "(" + variables.at(1).getName() + "," + variables.at(2).getName() + "," + variables.at(0).getName() + ");\n";
	}
	else if (operand.compare("/") == 0) {	//DIV
		toReturn = "DIV div" + to_string(num) + "(" + variables.at(1).getName() + "," + variables.at(2).getName() + "," + variables.at(0).getName() + ");\n";
	}
	else if (operand.compare("%") == 0) {	//MOD
		toReturn = "MOD mod" + to_string(num) + "(" + variables.at(1).getName() + "," + variables.at(2).getName() + "," + variables.at(0).getName() + ");\n";
	}
	else if (operand.compare("+") == 0) {	//INC
		toReturn = "INC inc" + to_string(num) + "(" + variables.at(1).getName() + "," + variables.at(0).getName() + ");\n";
	}
	else if (operand.compare("-") == 0)	{ //DEC
		toReturn = "DEC dec" + to_string(num) + "(" + variables.at(1).getName() + "," + variables.at(0).getName() + ");\n";
	}
	else {
		toReturn = "FAILED";
	}
	return toReturn;

}

int main(int argc, char *argv[]) {
	int i, pos, operandCount = 0, count = 0;
	bool operation, validVar = false;

	//Step 1: Read file input line by line
	ifstream iFile;
	string line, operand, currType, bitWidth, varNames, currName;
	string delimiter = ", ";

	Variable tempVar;
	vector<Variable> allVariables;
	vector<Variable> currOperand;

	//iFile.open("C:/Users/cassi/Documents/School/UofA7th Sem/CSCV 352/ECE474Project2/ECE474Project2/474a_circuit1.txt");
	//iFile.open("C:/Users/evanj/OneDrive/SchoolWork/4Senior/574/ECE474Project2/assignment_2_circuits/474a_circuit1.txt");
	iFile.open("./assignment_2_circuits/474a_circuit1.txt"); //THIS IS THE ONE BOYS
	//iFile.open("Test.txt");

	if (iFile.is_open()) {
		while (!iFile.eof()) {
			string val;
			count = 0;
			operation = false;
			validVar = false;
			currOperand.clear();
			operand="="; //Assume Reg
			
			getline(iFile, line); //Pull in line

			//Decompisition of Input, Output, Wire
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

					allVariables.push_back(tempVar);
				}

				if (!varNames.empty()) {
					tempVar.setVarType(currType);
					tempVar.setBitWidth(stoi(bitWidth.substr(begin, bitWidth.length() - 1)));
					tempVar.setName(varNames);
					allVariables.push_back(tempVar);
				}
			}
			else {
				istringstream opStream(line);
				if (line.compare("") == 0) {
					continue;
				}
				//Decompisition of Operator
				while (opStream >> val) {
					//Check the variables validity
					if (count == 0 || count == 2 || count == 4 || count == 6) {
						for (i = 0; i < allVariables.size(); i++) {
							//Make sure var exists
							if (allVariables.at(i).getName().compare(val) == 0) {
								validVar = true;
								currOperand.push_back(allVariables[i]);
								break;
							}
						}
						if (validVar == false) 
							return EXIT_FAILURE;
					}
					//Get the operand (= for reg, +,-... for others)
					if (count==1 || count == 3)
						operand = val;
					count += 1;
				}
				cout << callOperator(currOperand, operand, operandCount);
				operandCount += 1;
			}
			/*for (auto i : allVariables) {
					i.toString();
			}*/
			//Call Operand function
		}
	}
	else {
		return -1;
	}

	//Convert to Verilog line of code and export to .v
	return 0;
};
