/* Write a program to fold input line into two or more shorter lines after non-blank
   character occurs before the n-th column of input line */

#include <stdio.h>
#include <stdbool.h>

#define MAXCOL 100
#define TABVAL 8
#define NCOL 80

char inputLine[MAXCOL];
char tempLine[MAXCOL];
char testLine[MAXCOL] = "aaaa bbbbb\tccc\nccdjfbgfbgfb\tvfdvfdvfdfd\nsdcdscdscdsc";
char testLine_2[MAXCOL] = "aaaaaaaaaaaaaaaaaaaaaaaaaa aa";

int findLastNonBlankPosition(char line[]);
void processSpace(char result_1[], char result_2[], char line[]);
void processNewLine(char result_1[], char result_2[], char line[]);
void processTab(char result_1[], char result_2[], char line[]);
void foldInputLine(char line[]);
void processNormalCase(char line[]);
void processLongLineCase(void);
bool checkSpaceCase(char line[]);
bool checkTabCase(char line[]);
bool checkNewLineCase(char line[]);
bool checkAtomic(char line[]);
bool checkLongInputLine(char line[]);

int main1_22() {
	foldInputLine(testLine);
	return 0;
}

void foldInputLine(char line[]) {
	if (checkLongInputLine(line)) {
		processLongLineCase(line);
	}
	else {
		processNormalCase(line);
	}
}

bool checkLongInputLine(char line[]) {
	int i = 0, length = 0;

	while (line[i] != '\0') {
		++length;
		++i;
	}

	for (i = 0; i < length; ++i) {
		if (((line[i] == ' ') || (line[i] == '\b') || (line[i] == '\t') || (line[i] == '\n')) && (i <= NCOL)) {
			return false;
		}
	}

	return true;
}

void processLongLineCase() {
	printf("I'm so sorry because this is a long input\nSo we won't process it. Please try another input line");
}

bool checkAtomic(char line[]) {
	int i = 0, length = 0;
	char c;

	while (line[i++] != '\0') {
		++length;
	}
	i = 0;
	while ((c = line[i]) != '\0') {
		if (((c == ' ') || (c == '\b') || (c == '\t') || (c == '\n')) && (i != 0) && (i != length - 1)) {
			return false;
		}
		++i;
	}
	return true;
}

void processNormalCase(char line[]) {
	char result_1[MAXCOL];
	char result_2[MAXCOL];
	if (checkSpaceCase(line)) {
		processSpace(result_1, result_2, line);
		if (!checkAtomic(result_1)) {
			processNormalCase(result_1);
		}
		if (!checkAtomic(result_2)) {
			processNormalCase(result_2);
		}
		if ((checkAtomic(result_1) == true) && (checkAtomic(result_2) == true)) {
			return 0;
		}
	}
	else if (checkTabCase(line)) {
		processTab(result_1, result_2, line);
		if (!checkAtomic(result_1)) {
			processNormalCase(result_1);
		}
		if (!checkAtomic(result_2)) {
			processNormalCase(result_2);
		}
		if ((checkAtomic(result_1) == true) && (checkAtomic(result_2) == true)) {
			return 0;
		}
	}
	else if (checkNewLineCase(line)) {
		processNewLine(result_1, result_2, line);
		if (!checkAtomic(result_1)) {
			processNormalCase(result_1);
		}
		if (!checkAtomic(result_2)) {
			processNormalCase(result_2);
		}
		if ((checkAtomic(result_1) == true) && (checkAtomic(result_2) == true)) {
			return 0;
		}
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

int findLastNonBlankPosition(char line[]) {
	int indexLNB = 0, indexB = 0;	  //lnb: last non-blank character before n-th column of input line
	for (int i = 0; i < NCOL; ++i) {
		if ((line[i] == ' ') || (line[i] == '\b') || (line[i] == '\t') || (line[i] == '\n')) {
			indexB = i;
		}
	}
	for (int j = 0; j < indexB; ++j) {
		if ((line[j] != ' ') && (line[j] != '\b') && (line[j] != '\t') && (line[j] != '\n')) {
			indexLNB = j;
		}
	}
	return indexLNB;
}

void processSpace(char result_1[], char result_2[], char line[]) {
	int index_1, index_2 = 0;

	int indexLNB = 0, indexSpace = 0;
	indexLNB = findLastNonBlankPosition(line);
	indexSpace = indexLNB + 1;
	for (index_1 = 0; index_1 < indexSpace; index_1++) {
		result_1[index_1] = line[index_1];
	}
	result_1[index_1] = '\0';

	for (int j = indexSpace + 1; j < MAXCOL; j++) {
		result_2[index_2++] = line[j];
	}
	result_2[index_2] = '\0';

	printf("Result_1: %s\nResult_2: %s\n", result_1, result_2);
}

void processTab(char result_1[], char result_2[], char line[]) {
	int indexLNB = 0, indexTab = 0;
	int i, j, t;

	indexLNB = findLastNonBlankPosition(line);
	indexTab = indexLNB + 1;

	j = 0;
	for (int i = 0; i < MAXCOL; i++) {
		if (i != indexTab) {
			tempLine[j++] = line[i];
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

void processNewLine(char result_1[], char result_2[], char line[]) {
	int index_1, index_2 = 0;

	int indexLNB = 0, indexNB = 0;
	indexLNB = findLastNonBlankPosition(line);
	indexNB = indexLNB + 1;
	for (index_1 = 0; index_1 < indexNB; index_1++) {
		result_1[index_1] = line[index_1];
	}
	result_1[index_1] = '\0';

	for (int j = indexNB + 1; j < MAXCOL; j++) {
		result_2[index_2++] = line[j];
	}
	result_2[index_2] = '\0';

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