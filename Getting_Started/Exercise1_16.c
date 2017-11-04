#include <stdio.h>

#define MAXLINE 1000

int getLine1_16(char s[], int maxLine);
void copy1_16(char to[], char from[]);

int main() {
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len = getLine1_16(line, MAXLINE)) > 0) {
		if (len > max) {
			max = len;
			copy1_16(longest, line);
		}
	}
	if (max > 0) {
		printf("Text longest is: %s\n", longest);
		printf("Length of longest is: %d\n", max);
	}
	return 0;
}

int getLine1_16(char s[], int limit) {
	int i, c;

	for (i = 0; (i < limit - 1) && ((c = getchar()) != EOF) && (c != '\n'); ++i) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void copy1_16(char to[], char from[]) {
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0') {
		++i;
	}
}