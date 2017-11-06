#include <stdio.h>

#define MAXLINE 1000

void reverseString(char sourceString[], char reversedString[]);
int processLine1_19(char sourceString[], int maxLine);

/* Program reverse characters of string s */

int main() {
	//char sourceString[17] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','e','\n','\0' };
	//char string[10] = "abcdefghl";
	//printf("%s\n", sourceString);
	char sourceString[MAXLINE];
	char reversedString[MAXLINE];
	processLine1_19(sourceString, MAXLINE);
	reverseString(sourceString, reversedString);
	printf("%s\n", reversedString);
	return 0;
}

int processLine1_19(char sourceString[], int maxline) {
	int i, c;
	for (i = 0; (i < maxline - 1) && ((c = getchar()) != EOF) && (c != '\n'); ++i) {
		sourceString[i] = c;
	}
	if (c == '\n') {
		sourceString[i] = c;
		++i;
	}
	sourceString[i] = '\0';
	return i;
}

void reverseString(char sourceString[], char reversedString[]) {
	int lenSource = 0, lenReverse = 0, indexSource = 0, indexReverse;

	while (sourceString[lenSource++] != '\n') {
		lenReverse++;
	}
	for (indexReverse = lenReverse - 1; indexReverse >= 0; --indexReverse) {
		reversedString[indexReverse] = sourceString[indexSource++];
	}
	reversedString[lenReverse] = '\n';
	reversedString[lenReverse + 1] = '\0';
}