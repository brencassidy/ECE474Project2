/*
Name: Brendan Cassidy, Diego Alcantra, Evan Weiler, Logan Knott
Project: ECE 474/574 Project 2

Description: 
	This project is a parser for Behavioral netlists that will output 
	the top Module verilog file
*/

int main(int argc, char *argv[]) {

	//Step 1: Read file input line by line
	std::ifstream iFile(argv[1]);
	std::string line;


	while (!iFile.eof()) {
		//Read first keyword to check type
		//line.c_str();
		printf("%s", line.c_str);

	}
	//Convert to Verilog line of code and export to .v
	return 0;
};
