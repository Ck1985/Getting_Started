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
	int i, j = 0, headTab = 0, tailTab, countBlanks;
	int index = 0, firstFlag = 1, fraction = 0, countCharacter = 0, phan_bu = 0;
	int oldValue = 0;
	extern char inputLine[], processedLine[];

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
			i = i - 2;
			if (countBlanks >= 8) {
				/* Most difficult part of program */
				
				/*--------------------------------*/
			}
			else {
				processedLine[j] = inputLine[i];
				++j;
				++countCharacter;
			}
		}
		else {
			processedLine[j] = inputLine[i];
			++j;
			++countCharacter;
		}
	}
}

