#include <stdio.h>

#define MAXLINE 1000
#define TABINC 8

int length = 0;
char inputLine[MAXLINE];
char processedLine[MAXLINE];

int getLine1_21(void);
void processLine1_21(void);

int main1_21() {
	extern char processedLine[];
	int len = 0;
	while ((len = getLine1_21()) > 0) {
		processLine1_21();
		printf("%s\n", processedLine);
	}
	return 0;
}

int getLine1_21(void) {
	int c, i;
	extern char inputLine[];

	for (i = 0; ((c = getchar()) != EOF) && (i < (MAXLINE - 1)) && (c != '\n'); ++i) {
		inputLine[i] = c;
	}
	if (c == '\n') {
		inputLine[i] = c;
		++i;
	}
	inputLine[i] = '\0';
	return i;
}

void processLine1_21(void) {
	int i, j = 0, index = 0, numChar = 0, numSpace = 0, fraction, oldFraction = 0, flag = 1;
	int headTab = 0, tailTab, even;
	extern char inputLine[], processedLine[];

	while (inputLine[index] != '\n') {
		index++;
	}
	length = index;

	for (i = 0; i < length; ++i) {
		if (inputLine[i] == ' ') {
			numSpace = 1;
			while (inputLine[++i] == ' ') {
				++numSpace;
			}
			if (numSpace >= TABINC) {
				i = i - 1;
				tailTab = i;
				even = numSpace / TABINC;
				numChar = numChar + oldFraction;
				if (flag == 1) {
					fraction = (tailTab - headTab + 1) - numChar - (TABINC - (numChar % TABINC));
				}
				else {
					fraction = (tailTab - headTab) - numChar - (TABINC - (numChar % TABINC));
				}
				oldFraction = fraction;
				headTab = tailTab - fraction;
				processedLine[j] = '\t';
				++j;
				for (int n = 1; n <= fraction; ++n) {
					processedLine[j] = ' ';
					++j;
				}
				numChar = 0;
				flag = 0;
			}
			else {
				i = i - numSpace;
				processedLine[j] = inputLine[i];
				++j;
				++numChar;
			}
		}
		else {
			processedLine[j] = inputLine[i];
			++j;
			++numChar;
		}
	}
}

