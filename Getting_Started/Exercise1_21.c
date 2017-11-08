#include <stdio.h>

#define MAXLINE 1000
#define TABINC 8

int length = 0;
char inputLine[MAXLINE];
char processedLine[MAXLINE];

int getLine1_21(void);
void processLine1_21(void);

int main1_21() {
	getLine1_21();
	processLine1_21();
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
	int i, j = 0, countBlanks, genBlanks, even, odd;
	extern char processedLine[];

	while (inputLine[length] != '\n') {
		length++;
	}

	for (i = 0; i < length; ++i) {
		if ((inputLine[i] == ' ') || (inputLine[i] == '\b')) {
			countBlanks = 1;
			while ((inputLine[++i] == ' ') || (inputLine[++i] == '\b')) {
				++countBlanks;
			}
			i = i - countBlanks;
			if (countBlanks >= TABINC) {
				if ((countBlanks % TABINC) == 0) {
					even = countBlanks / TABINC;
					for (int k = 1; k <= even; ++k) {
						processedLine[j] = '\t';
					}
				}
				else {
					even = countBlanks / TABINC;
					odd = countBlanks % TABINC;
					for (int m = 1; m <= even; ++m) {
						processedLine[j++] = '\t';
					}
					for (int n = 1; n <= odd; ++n) {
						processedLine[j++] = ' ';
					}
				}
			}
		}
		else {
			processedLine[j] = inputLine[i];
			++j;
		}
	}
}