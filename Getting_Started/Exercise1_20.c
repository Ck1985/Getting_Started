/* Write a program Detab which replaces tabs in input text 
   with a proper number of blanks to space */

#include <stdio.h>

#define MAXLINE 1000
#define TABIN	C 8

int index = 0;
char inputLine[MAXLINE];
char locationTab[MAXLINE];
char editedLine[MAXLINE];

int getLine1_20(void);
void processTabs1_20(void);

int main() {
	getLine1_20();
	processTabs1_20();
	printf("%s\n", locationTab);
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
	int i, j = 0, length, startTab, stopTab;
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

	}
}

/*#include<stdio.h>
#define TABINC 8

int main(void)
{
	int nb, pos, c;

	nb = 0;
	pos = 1;

	while ((c = getchar()) != EOF)
	{
		if (c == '\t')
		{
			nb = TABINC - ((pos - 1) % TABINC);

			while (nb > 0)
			{
				putchar('#');
				++pos;
				--nb;
			}
		}
		else if (c == '\n')
		{
			putchar(c);
			pos = 1;
		}
		else
		{
			putchar(c);
			++pos;
		}
	}

	return 0;
}*/