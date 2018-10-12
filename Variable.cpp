#include <stdio.h>
#include "Variable.hpp"


Variable::Variable() { //default constructor
    this->name = "undefined";
    this->vartype = "undefined";
    this->bitwidth = 0;
}

Variable::Variable(std::string name, std::string vartype, int bitwidth) {
    this->name = name;
    this->vartype = vartype;
    this->bitwidth = bitwidth;
}

//getters
std::string Variable::getName() const {
    return this->name;
}
std::string Variable::getVarType() const{
    return this->vartype;
}
int Variable::getBitWidth() const{
    return this->bitwidth;
}

//setters
void Variable::setName(std::string name){
    this->name = name;
}
void Variable::setVarType(std::string varType){
    this->vartype = vartype;
}
void Variable::setBitWidth(int bitwidth){
    this->bitwidth = bitwidth;
}
