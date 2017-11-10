#include <stdio.h>

#define MAXLINE 1000
#define TABINC 8

int length = 0;
char inputLine[MAXLINE];
char processedLine[MAXLINE];

int getLine1_21(void);
void processLine1_21(void);

int main() {
	getLine1_21();
	processLine1_21();
	printf("%s\n", processedLine);
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
	int i, j = 0, countBlanks, genBlanks, even, odd, index = 0;
	int startTab, stopTab, flagTab = 1, phan_bu = 0;
	extern char processedLine[];

	while (inputLine[index] != '\n') {
		index++;
	}
	length = index;
	for (i = 0; i < length; ++i) {
		if ((inputLine[i] == ' ') || (inputLine[i] == '\b')) {
			countBlanks = 1;
			while ((inputLine[++i] == ' ') || (inputLine[++i] == '\b')) {
				++countBlanks;
			}
			if (countBlanks >= TABINC) {
					if ((countBlanks % TABINC) == 0) {
						even = countBlanks / TABINC;
							for (int k = 1; k <= even + phan_bu; ++k) {
								processedLine[j++] = '\t';
							}											
					}
					else {							
							even = countBlanks / TABINC;
							odd = countBlanks % TABINC;
							for (int m = 1; m <= even; ++m) {
								processedLine[j++] = '\t';
							}
							for (int n = 1; n <= odd + phan_bu; ++n) {
								processedLine[j++] = ' ';
							}
					}
			}
			i = i - 2;
		}
		else {
			processedLine[j] = inputLine[i];
			++j;
		}
	}
}