#ifndef RECR_H_
#define RECR_H_

#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int strLength(char* str);
float addOdd(float* array, int size);
int countVowels(char* str, int strLen);
int isPalindrome(char* str, int pos, int strLen);
void findReplace(char* str, int strLen, char from, char to);
int recEq(int n);

#endif
