#include "dataType.h"

dataType::dataType(){

	var1 = 0;
	var2 = 0;
	var3 = 0;
}

dataType::dataType(int a, int b, int c){

	var1 = a;
	var2 = b;
	var3 = c;
}

dataType::~dataType(){}

void dataType::printData(){

	cout << "var1 = " << var1 << endl;
	cout << "var2 = " << var2 << endl;
	cout << "var3 = " << var3 << endl;
}

dataType& dataType::operator+=(const dataType& other){

	this->var1 += other.var1;
	this->var2 += other.var2;
	this->var3 += other.var3;
	return *this;
}

bool dataType::operator==(const dataType& other){

	if((this->var1 == other.var1) && (this->var2 == other.var2) && (this->var3 == other.var3))return true;

	else return false;
}

void dataType::analyzeBool(bool result){

	if(result == 1)cout << "Boolean result: TRUE" << endl;
	else cout << "Boolean result: FALSE" << endl;
}
