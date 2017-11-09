/* Write a program Detab which replaces tabs in input text 
   with a proper number of blanks to space */

#include <stdio.h>

#define MAXLINE 1000
#define TABINC 8

int index = 0;
char inputLine[MAXLINE];
char locationTab[MAXLINE];
char editedLine[MAXLINE];

int getLine1_20(void);
void processTabs1_20(void);

int main() {
	extern char inputLine[], locationTab[], editedLine[];
	getLine1_20();
	processTabs1_20();
	printf("%s\n", editedLine);
	return 0;
}

int getLine1_20(void) {
	int c, i;
	extern char inputLine[];

	for (i = 0; ((c = getchar()) != EOF) && (i < MAXLINE - 1) && (c != '\n'); ++i) {
		inputLine[i] = c;
	}
	if (c == '\n') {
		inputLine[i] = c;
		++i;
	}
	inputLine[i] = '\0';
	return i;
}

void processTabs1_20(void) {
	int i, j = 0, length, startTab, stopTab, flagTab = 1, oppositePart;
	extern int index;
	extern char inputLine[], editedLine[], locationTab[];

	while (inputLine[index] != '\n') {
		index++;
	}
	length = index;

	for (i = 0; i < length; ++i) {
		locationTab[i] = '0';
	}
	locationTab[++i] = '\n';
	locationTab[++i] = '\0';
	i = 0;

	for (int k = 0; k < length; ++k) {
		if (inputLine[k] == '\t') {
			locationTab[k] = '1';
		}
	}

	for (i = 0; i < length; ++i) {
		if ((inputLine[i] == '\t') && (flagTab == 1)) {
			startTab = i;
			oppositePart = TABINC - startTab;
			for (int k = 1; k <= oppositePart; ++k) {
				editedLine[j] = '#';
				++j;
			}
			stopTab = startTab;
			flagTab = 0;
		}
		else if (inputLine[i] == '\t') {
			startTab = i;
			oppositePart = TABINC - (startTab - stopTab) + 1;
			for (int k = 1; k <= oppositePart; ++k) {
				editedLine[j] = '#';
				++j;
			}
			stopTab = startTab;
		}
		else {
			editedLine[j] = inputLine[i];
			++j;
		}
	}

	editedLine[j++] = '\n';
	editedLine[j] = '\0';
}