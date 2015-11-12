#include "recr.h"

int strLength(char* str){

	int i = 0;
	while(str[i] != '\0'){

		i++;
	}
	return i;
}

		
float addOdd(float* array, int size){

	if(size == 1){

		return 0;
	}
	else if(size == 2){

		return array[1];
	}
	else if(size % 2 == 0){

		return(array[size - 1] + addOdd(array, (size - 2)));
	}
	else if(size % 2 == 1){

		return(array[size - 2] + addOdd(array, (size - 2)));
	}
}

int countVowels(char* str, int strLen){

	if(strLen == 1){

		if((str[0] == 'a') || (str[0] == 'e') || (str[0] == 'i') || (str[0] == 'o') || (str[0] == 'u') || (str[0] == 'A') || (str[0] == 'E') || (str[0] == 'I') || (str[0] == 'O') || (str[0] == 'U')){

			return 1;
		}
		else{

			return 0;
		}
	}
	else if(str[strLen - 1] == 'a' || str[strLen] == 'e' || str[strLen] == 'i' || str[strLen] == 'o' || str[strLen] == 'u' || str[strLen] == 'A' || str[strLen] == 'E' || str[strLen] == 'I' || str[strLen] == 'O' || str[strLen] == 'U'){

		return(1 + countVowels(str, (strLen - 1)));
	}
	else{

		return(countVowels(str, (strLen - 1)));
	}
}

int isPalindrome(char* str, int pos, int strLen){

	int length = strLen - pos;
	if(length == 1){

		return 1;
	}
	else if(length == 2){

		if(str[pos] == str[strLen - 1]){

			return 1;
		}
		else{

			return -1;
		}
	}
	else if(str[pos] == str[strLen - 1]){

		pos++;
		strLen--;
		return(isPalindrome(str, pos, strLen));
	}
	else{

		return -1;
	}
}

void findReplace(char* str, int strLen, char from, char to){

	if(strLen == 1){

		if(str[strLen - 1] == from){

			str[strLen - 1] = to;
		}
	return;
	}
	else if(str[strLen - 1] == from){

		str[strLen - 1] = to;
		findReplace(str, (strLen - 1), from, to);
	}
	else{

		findReplace(str, (strLen - 1), from, to);
	}
}

int recEq(int n){

	if(n < 0){

		printf("\nInput value to recEq function must be > 0.\n");
		return -1;
	}
	else if(n == 0){

		return 0;
	}
	else if(n == 1){

		return 1;
	}
	else if(n == 2){

		return 2;
	}
	else{

		return((recEq(n - 1)) - (recEq(n - 2)) + (recEq(n - 3)));
	}
}





