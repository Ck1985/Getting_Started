#include <stdio.h>

#define MAXLINE 1000     /* Maximum input line size */

int max;                 /* maximum length so far */
char line[MAXLINE];      /* current input line */
char longest[MAXLINE];   /* longest line saved here */

int getLine_2(void);
void copy_2(void);

int mainEVAS() {
	int len;
	extern int max;
	extern char longest[];

	max = 0;
	while ((len = getLine_2()) > 0) {
		if (len > max) {
			max = len;
			copy_2();
		}
	}
	if (max > 0) {
		printf("The longest text input: %s\n", longest);
	}
	return 0;
}

/* getLine: Specialized version */
int getLine_2(void) {
	int c, i;
	extern char line[];

	for (i = 0; (i < MAXLINE - 1) && ((c = getchar()) != EOF) && (c != '\n'); ++i) {
		line[i] = c;
	}
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

/* copy: Specialized version */
void copy_2(void) {
	int i;
	extern char line[], longest[];

	i = 0;
	while ((longest[i] = line[i]) != '\0') {
		++i;
	}
}