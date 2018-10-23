#ifndef VARIABLE_HPP
#define VARIABLE_HPP

#include <string>
#include <iostream>

class Variable {
private:
    std::string name;
    std::string vartype;
    int bitwidth;
    
public:
	Variable() { //default constructor
		this->name = "undefined";
		this->vartype = "undefined";
		this->bitwidth = 0;
	}

	Variable(std::string name, std::string vartype, int bitwidth) {
		this->name = name;
		this->vartype = vartype;
		this->bitwidth = bitwidth;
	}
    
	//getters
	std::string getName() const {
		return this->name;
	}
	std::string getVarType() const {
		return this->vartype;
	}
	int getBitWidth() const {
		return this->bitwidth;
	}
    
    //setters
	void setName(std::string name) {
		this->name = name;
	}
	void setVarType(std::string varType) {
		this->vartype = varType;
	}
	void setBitWidth(int bitwidth) {
		this->bitwidth = bitwidth;
	}

	void toString() {
		std::cout << "Var Name: " << name << " Var type: " << vartype << " Bit Width: " << bitwidth << std::endl;
	}
};

#endif
