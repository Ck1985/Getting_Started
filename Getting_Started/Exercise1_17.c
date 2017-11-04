#include <stdio.h>
#include <stdbool.h>

#define MAXLINE 1000

int processLine(char inputLine[], int maxLine);
bool checkLengthLine(char inputLine[], int maxLine);

/* Print all input line which has length are longer than 80 character */

int main1_17() {
	int length;
	char inputLine[MAXLINE];
	//char lineLength80[MAXLINE];

	while ((length = processLine(inputLine, MAXLINE)) > 0) {
		if (checkLengthLine(inputLine, MAXLINE)) {
			printf("%s\n", inputLine);
		}
	}
	return 0;
}

int processLine(char inputLine[], int limit) {
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

bool checkLengthLine(char inputLine[], int limit) {
	if (processLine(inputLine, limit) > 80) {
		return true;
	}
	else {
		return false;
	}
}

