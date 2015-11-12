#ifndef DATATYPE_H_
#define DATATYPE_H_

#include <iostream>

using namespace std;

class dataType{

	public:

		dataType();
		dataType(int a, int b, int c);
		~dataType();
		void printData();
		bool operator ==(const dataType& other);
		dataType& operator +=(const dataType& other);
		void analyzeBool(bool result);
		
	private:

		int var1;
		int var2;
		int var3;
};

#endif
