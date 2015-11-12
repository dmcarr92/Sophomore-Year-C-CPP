#include "recr.h"

int main(){

// PART 1:

	srand(time(NULL));
	float sum1 = 0.0;
	float* array1 = malloc(sizeof(float) * 9);
	int i = 0;
	for(i;i < 9;i++){

		array1[i] = (rand() % 10000) / 100.0;
		printf("\n%.2f",array1[i]);
	}
	sum1 += addOdd(array1, 9);
	printf("\n\nsum: %.2f\n",sum1);

// PART 2:

	printf("\ngot to part 2\n");
	int sum2 = 0;
	char* str1 = "Hello, my name is Dillon!";
	int length1 = strLength(str1);
	char* str2 = "asdfghjklkjhgfdsa";
	int length2 = strLength(str2);
	sum2 += countVowels(str1, length1);
	printf("\nNumber of vowels in '%s': %d\n",str1,sum2);

// PART 3:

	printf("\ngot to part 3\n");
	int checkPal = 0;
	checkPal = isPalindrome(str1, 0, length1);
	printf("\nIs '%s' a palindrome? %d\n",str1,checkPal);
	checkPal = isPalindrome(str2, 0, length2);
	printf("\nIs '%s' a palindrome? %d\n",str2,checkPal);

// PART 4:

	printf("\ngot to part 4\n");
	char str3[] = "recursion can suck a dong.";
	int length3 = strLength(str3);
	findReplace(str3, length3, 'd', 'b');
	printf("\n%s\n",str3);

// PART 5:

	printf("\ngot to part 5\n\n");
	int n = 0;
	int recResult;
	for(n;n <= 15;n++){

		recResult = recEq(n);
		printf("recEq(%d) = %d\n",n,recResult);
	}
	return 0;
}
