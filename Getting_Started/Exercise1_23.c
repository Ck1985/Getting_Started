/* Writing a program which removes all Comments in C file
   Process quoted String and character constant properly */

#include <stdio.h>

#define MAXLINE1_23 100

int indexSI = 0, indexR = 0, countSlash = 0;
char sourceInput[MAXLINE1_23];
char result[MAXLINE1_23];

int getLine1_23();
void removeCommentsQuotedString(char line[]);
void processRecursion(char line[]);

int main1_23() {
	getLine1_23();
	removeCommentsQuotedString(sourceInput);
	printf("%s\n", result);
	return 0;
}

int getLine1_23() {
	int len, c;

	len = 0;
	while (((c = getchar()) != EOF) && (c != '\n')) {
		sourceInput[len] = c;
		++len;
	}
	sourceInput[len] = '\0';
	return len;
}

void removeCommentsQuotedString(char line[]) {
	extern char sourceInput[], result[];
	extern int indexSI, indexR, countSlash;

	while (sourceInput[indexSI] != '\0') {
		if (sourceInput[indexSI] == '/') {
			processRecursion(line);
			result[indexR++] = sourceInput[indexSI++];
		}
		else if ((sourceInput[indexSI] == '\'') || (sourceInput[indexSI] == '"')) {

		}
		else {
			result[indexR] = sourceInput[indexSI];
			++indexR;
			++indexSI;
		}
	}
}

void processRecursion(char line[]) {
	extern char sourceInput[], result[];
	extern int indexSI, indexR, countSlash;
	if (sourceInput[indexSI + 1] == '/') {
		result[indexR++] = sourceInput[indexSI++];
		processRecursion(line);
	}
	else if ((sourceInput[indexSI + 1] == '*') ) {
		countSlash = indexSI + 2;
		while ((sourceInput[countSlash] != '*') && (sourceInput[indexSI + 2] != '\\')) {
			countSlash++;
		}
		indexSI = countSlash + 2;
		return 0;
	} 
	else {
		return 0;
	}
}

void processQuotedString(char line[]) {
	
}