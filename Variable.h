#ifndef VARIABLE_H
#define VARIABLE_H

#include "Variable.cpp"
#include <string>

class Variable {
private:
    std::string name;
    std::string vartype;
    int bitwidth;
    
public:
    Variable(); //default constructor
    Variable(std::string name, std::string vartype, int bitwidth);
    
    //getters
    std::string getName() const;
    std::string getVarType() const;
    int getBitWidth() const;
    
    //setters
    void setName(std::string name);
    void setVarType(std::string varType);
    void setBitWidth(int bitwidth);
    
};

#endif
