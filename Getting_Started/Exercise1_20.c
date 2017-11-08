/* Write a program Detab which replaces tabs in input text 
   with a proper number of blanks to space */

#include <stdio.h>

#define MAXLINE 1000
#define TABINC 8

int index = 0;
char inputLine[MAXLINE];
char editedLine[MAXLINE];

int getLine1_20(void);
void processTabs1_20(void);

int main() {
	getLine1_20();
	processTabs1_20();
	printf("%s \n", editedLine);
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
	int i, j = 0, countTabs;
	extern int index;
	extern char inputLine[], editedLine[];

	while (inputLine[index] != '\n') {
		index++;
	}

	for (i = 0; i < index; ++i) {
		if (inputLine[i] == '\t') {
			countTabs = 1;
			while (inputLine[++i] == '\t') {
				++countTabs;
			}
			--i;
			for (int k = 1; k <= countTabs; k++) {
				for (int l = 0; l < TABINC; l++) {
					editedLine[j] = '#';
					++j;
				}
			}
		}
		else {
			editedLine[j] = inputLine[i];
			++j;
		}
	}
}