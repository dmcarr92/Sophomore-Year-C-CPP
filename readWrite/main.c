#include "readWrite.h"

int main(int argc, char* argv[]) {

	FILE* fp = openfileRead(argv[1]);
	FILE* out = openfileWrite(argv[2]);
	data* d = readData(fp);
	writeData(out, d);

	fclose(fp);
	fclose(out);
	free(d);

	return 0;

}