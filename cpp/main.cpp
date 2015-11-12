#include "dataType.h"

int main(){

	dataType data1;
	cout << "Printing data from: data1" << endl;
	data1.printData();
	dataType data2(1, 2, 3);
	data1 += data2;
	cout << "Printing data from: data1" << endl;
	data1.printData();
	bool equal = data1 == data2;
	data1.analyzeBool(equal);
	return 0;
}
