#include <stdio.h>

#define MAXLINE 1000

int processInputLine(char inputLine[], int maxline);
void removeBlanksTabs(char inputLine[], char textProcessed[MAXLINE], int maxline);

/* This program remove trailing blanks and tabs, remove all blank lines */

int main1_18() {
	char inputLine[MAXLINE];
	char textProcessed[MAXLINE];
	processInputLine(inputLine, MAXLINE);
	removeBlanksTabs(inputLine, textProcessed, MAXLINE);
	printf("%s\n", textProcessed);
	return 0;
}

int processInputLine(char inputLine[], int limit) {
	int i, c;

	for (i = 0; (i < limit - 1) && ((c = getchar()) != EOF) && (c != '\n'); ++i) {
		inputLine[i] = c;
	}
	if (c == '\n') {
		inputLine[i] = c;
		++i;
	}
	inputLine[i] = '\0';
	return i;
}

void removeBlanksTabs(char inputLine[], char textProcessed[MAXLINE], int limit) {
	int i = 0, j = 0;
	int count = 0;

	while (inputLine[i] != '\0') {
		if ((inputLine[i] == ' ') || (inputLine[i] == '\t') || (inputLine[i] == '\b')) {
			while ((inputLine[i] == ' ') || (inputLine[i] == '\t') || (inputLine[i] == '\b')) {
				++count;
				if (count >= 2) {
					++i;
				}
			}
		}
		if (count >= 2) {
			textProcessed[j] = ' ';
			textProcessed[++j] = inputLine[i];
			count = 0;
		}
		else {
			textProcessed[j] = inputLine[i];
			++i;
			++j;
		}
	}
	if (inputLine[i] == '\0') {
		textProcessed[j] = '\0';
	}
}