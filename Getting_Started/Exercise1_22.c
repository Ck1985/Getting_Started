/* Write a program to fold input line into two or more shorter lines after non-blank
   character occurs before the n-th column of input line */

#include <stdio.h>
#include <stdbool.h>

#define MAXCOL 80
#define TABVAL 8
#define NCOL 30

char inputLine[MAXCOL];

int findLastNonBlankPosition(char inputLine[]);

int main() {

	return 0;
}

void foldInputLine(char inputLine[]) {
	if (checkLongInputLine(inputLine)) {
		processLongLineCase(inputLine);
	}
	else {
		processNormalCase(inputLine);
	}
}

bool checkLongInputLine(char inputLine[]) {

}

void processLongLineCase(char inputLine[]) {

}

void processNormalCase(char inputLine[]) {
	if (checkSpaceCase(inputLine)) {
		processSpace(inputLine);
	}
	else if (checkTabCase(inputLine)) {
		processTab(inputLine);
	}
	else if (checkNewLineCase(inputLine)) {
		processNewLine(inputLine);
	}
}

bool checkSpaceCase(char inputLine[]) {
	bool isSpaceCase = false;
	int indexLNB = 0;
	indexLNB = findLastNonBlankPosition(inputLine);
	if ((inputLine[indexLNB + 1] == ' ') || (inputLine[indexLNB + 1] == '\b')) {
		isSpaceCase = true;
	}
	else {
		isSpaceCase = false;
	}
	return isSpaceCase;
}

bool checkTabCase(char inputLine[]) {
	bool isTabCase = false;
	int indexLNB = 0;
	indexLNB = findLastNonBlankPosition(inputLine);
	if ((inputLine[indexLNB + 1] == '\t')) {
		isTabCase = true;
	}
	else {
		isTabCase = false;
	}
	return isTabCase;
}

bool checkNewLineCase(char inputLine[]) {
	bool isNewLineCase = false;
	int indexLNB = 0;
	indexLNB = findLastNonBlankPosition(inputLine);
	if ((inputLine[indexLNB + 1] == '\n')) {
		isNewLineCase = true;
	}
	else {
		isNewLineCase = false;
	}
	return isNewLineCase;
}

int findLastNonBlankPosition(char inputLine[]) {
	extern char inputLine[];
	int indexLNB, indexLB;	  //lnb: last non-blank character before n-th column of input line
	for (int i = 0; i < NCOL - 1; ++i) {
		if ((inputLine[i] == ' ') || (inputLine[i] == '\b') || (inputLine[i] == '\t') || (inputLine[i] == '\n')) {
			indexLB = i;
		}
	}
	for (int j = 0; j < indexLB; ++j) {
		if ((inputLine[j] != ' ') && (inputLine[j] != '\b') && (inputLine[j] != '\t') && (inputLine[j] != '\n')) {
			indexLNB = j;
		}
	}
	return indexLNB;
}

void processSpace(char inputLine[]) {
	char result_1[MAXCOL];
	char result_2[MAXCOL];

	int indexFold = 0, countLeft;
	indexFold = findLastNonBlankPosition(inputLine);
	for (int i = 0; i < indexFold; i++) {
		result_1[i] = inputLine[i];
	}
	for (int j = indexFold + 1; j < MAXCOL; j++) {
		result_2[j] = inputLine[j];
	}
}

void processTab(char inputLine[]) {
	char tempLine[2 * MAXCOL];
}

void processNewLine(char inputLine[]) {

}