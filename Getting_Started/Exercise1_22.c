/* Write a program to fold input line into two or more shorter lines after non-blank
   character occurs before the n-th column of input line */

#include <stdio.h>
#include <stdbool.h>

#define MAXCOL 40
#define TABVAL 8
#define NCOL 20

char inputLine[MAXCOL];
char tempLine[MAXCOL];
char testLine[MAXCOL] = "aaaa bbbbb cccc\ndddddd eee";

int findLastNonBlankPosition(void);
void processSpace(void);
void processNewLine(void);
void processTab(void);
void foldInputLine(char line[]);
void processNormalCase(char line[]);
bool checkSpaceCase(char line[]);
bool checkTabCase(char line[]);
bool checkNewLineCase(char line[]);

int main() {
	extern char testLine[];
	foldInputLine(testLine);
	return 0;
}

void foldInputLine(char line[]) {
	if (checkLongInputLine(inputLine)) {
		processLongLineCase(inputLine);
	}
	else {
		processNormalCase(line);
	}
}

bool checkLongInputLine(char line[]) {

}

void processLongLineCase(char line[]) {

}

void processNormalCase(char line[]) {
	if (checkSpaceCase(line)) {
		processSpace(line);
	}
	else if (checkTabCase(line)) {
		processTab(line);
	}
	else if (checkNewLineCase(line)) {
		processNewLine(line);
	}
}

bool checkSpaceCase(char line[]) {
	bool isSpaceCase = false;
	int indexLNB = 0;
	indexLNB = findLastNonBlankPosition(line);
	if ((line[indexLNB + 1] == ' ') || (line[indexLNB + 1] == '\b')) {
		isSpaceCase = true;
	}
	else {
		isSpaceCase = false;
	}
	return isSpaceCase;
}

bool checkTabCase(char line[]) {
	bool isTabCase = false;
	int indexLNB = 0;
	indexLNB = findLastNonBlankPosition(line);
	if ((line[indexLNB + 1] == '\t')) {
		isTabCase = true;
	}
	else {
		isTabCase = false;
	}
	return isTabCase;
}

bool checkNewLineCase(char line[]) {
	bool isNewLineCase = false;
	int indexLNB = 0;
	indexLNB = findLastNonBlankPosition(line);
	if ((line[indexLNB + 1] == '\n')) {
		isNewLineCase = true;
	}
	else {
		isNewLineCase = false;
	}
	return isNewLineCase;
}

int findLastNonBlankPosition() {
	extern char testLine[];
	int indexLNB = 0, indexB = 0;	  //lnb: last non-blank character before n-th column of input line
	for (int i = 0; i < NCOL; ++i) {
		if ((testLine[i] == ' ') || (testLine[i] == '\b') || (testLine[i] == '\t') || (testLine[i] == '\n')) {
			indexB = i;
		}
	}
	for (int j = 0; j < indexB; ++j) {
		if ((testLine[j] != ' ') && (testLine[j] != '\b') && (testLine[j] != '\t') && (testLine[j] != '\n')) {
			indexLNB = j;
		}
	}
	return indexLNB;
}

void processSpace() {
	extern char testLine[];
	char result_1[MAXCOL];
	char result_2[MAXCOL];
	int index_1, index_2 = 0;

	int indexLNB = 0, indexSpace = 0;
	indexLNB = findLastNonBlankPosition(testLine);
	indexSpace = indexLNB + 1;
	for (index_1 = 0; index_1 < indexSpace; index_1++) {
		result_1[index_1] = testLine[index_1];
	}
	result_1[index_1] = '\n';
	result_1[++index_1] = '\0';

	for (int j = indexSpace + 1; j < MAXCOL; j++) {
		result_2[index_2++] = testLine[j];
	}
	result_2[index_2] = '\n';
	result_2[++index_2] = '\0';

	printf("Result_1: %s\nResult_2: %s\n", result_1, result_2);
}

void processTab() {
	extern char tempLine[];
	char result_1[MAXCOL];
	char result_2[MAXCOL];
	int indexLNB = 0, indexTab = 0;
	int i, j, t;

	indexLNB = findLastNonBlankPosition(testLine);
	indexTab = indexLNB + 1;

	j = 0;
	for (int i = 0; i < MAXCOL; i++) {
		if (i != indexTab) {
			tempLine[j++] = testLine[i];
		}
		else {
			for (int k = 1; k <= 8; k++) {
				tempLine[j++] = ' ';
			}
		}
	}

	for (i = 0; i < indexTab; i++) {
		result_1[i] = tempLine[i];
	}
	result_1[i] = '\0';

	t = 0;
	for (j = indexTab + 8; j < MAXCOL + 7; j++) {
		result_2[t++] = tempLine[j];
	}
	result_2[t] = '\0';

	printf("Result_1: %s\nResult_2: %s\n", result_1, result_2);
}

void processNewLine() {
	extern char testLine[];
	char result_1[MAXCOL];
	char result_2[MAXCOL];
	int index_1, index_2 = 0;

	int indexLNB = 0, indexNB = 0;
	indexLNB = findLastNonBlankPosition(testLine);
	indexNB = indexLNB + 1;
	for (index_1 = 0; index_1 < indexNB; index_1++) {
		result_1[index_1] = testLine[index_1];
	}
	result_1[index_1] = '\n';
	result_1[++index_1] = '\0';

	for (int j = indexNB + 1; j < MAXCOL; j++) {
		result_2[index_2++] = testLine[j];
	}
	result_2[index_2] = '\n';
	result_2[++index_2] = '\0';

	printf("Result_1: %s\nResult_2: %s\n", result_1, result_2);
}

/*int getLine1_22(void) {
	int c, i;
	extern char testLine[];

	for (i = 0; ((c = getchar()) != EOF) && (i < (MAXCOL - 1)); ++i) {
		testLine[i] = c;
	}
	if (c == '\n') {
		testLine[i] = c;
		++i;
	}
	testLine[i] = '\0';
	return i;
}*/