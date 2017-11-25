/* Program to check rudimentary syntax errors like unmatch braces,brakets or parenthesis */

/*#include<stdio.h>

int brace, brack, paren;

void incomment();
void inquote(int c);
void search(int c);

int main(void)
{
	int c;

	extern int brace, brack, paren;

	while ((c = getchar()) != EOF)
		if (c == '/')
			if ((c = getchar()) == '*')
				incomment();
			else
				search(c);
		else if (c == '\'' || c == '"')
			inquote(c);
		else
			search(c);

	if (brace < 0)
	{
		printf("Unmatched Braces\n");
		brace = 0;
	}
	else if (brack < 0)
	{
		printf("Unmatched brackets\n");
		brack = 0;
	}
	else if (paren < 0)
	{
		printf("Unmatched parenthesis\n");
		paren = 0;
	}

	if (brace > 0)
		printf("Unmatched braces\n");
	else if (brack > 0)
		printf("Unmatched brackets\n");
	else if (paren > 0)
		printf("Unmatched parenthesis\n");

	return 0;
}

void incomment()
{
	int c, d;

	c = getchar();
	d = getchar();

	while (c != '*' || d != '/')
	{
		c = d;
		d = getchar();
	}
}

void inquote(int c)
{
	int d;

	putchar(c);

	while ((d = getchar()) != c)
		if (d == '\\')
			getchar();
}

void search(int c)
{
	extern int brace, brack, paren;

	if (c == '{')
		--brace;
	else if (c == '}')
		++brace;
	else if (c == '(')
		--brack;
	else if (c == ')')
		++brack;
	else if (c == '[')
		--paren;
	else if (c == ']')
		++paren;
}*/

/* ---------------------------------------------------------- */

/* Write a program that check rudimentary error syntax C language */

#include <stdio.h>
#include <stdbool.h>

#define MAXLINE 100

char sourceLine[MAXLINE];

int getLine1_24(void);
bool checkErrorBracket(char line[]);
bool checkErrorComments(char line[]);

int main1_24() {
	getLine1_24();
	checkErrorBracket(sourceLine);
	checkErrorComments(sourceLine);
	return 0;
}

int getLine1_24() {
	extern char sourceLine[];
	int c, index = 0;

	while ((c = getchar()) != EOF) {
		sourceLine[index++] = c;
	}
	sourceLine[index] = '\0';
	return index;
}

bool checkErrorBracket(char line[]) {
	int index = 0;
	int curly_Bracket, round_Bracket, square_Bracket;
	curly_Bracket = round_Bracket = square_Bracket = 0;

	while (line[index] != '\0') {
		if (line[index] == '{') {
			--curly_Bracket;
		}
		else if (line[index] == '}') {
			++curly_Bracket;
		}
		else if (line[index] == '(') {
			--round_Bracket;
		}
		else if (line[index] == ')') {
			++round_Bracket;
		}
		else if (line[index] == '[') {
			--square_Bracket;
		}
		else if (line[index] == ']') {
			++square_Bracket;
		}
		++index;
	}

	if (curly_Bracket < 0) {
		printf("Error Missing curly bracket !");
	}
	else if (curly_Bracket > 0) {
		printf("Error plenty curly bracket !");
	}

	if (round_Bracket < 0) {
		printf("Error Missing round bracket !");
	}
	else if (round_Bracket > 0) {
		printf("Error plenty round bracket !");
	}

	if (square_Bracket < 0) {
		printf("Error Missing square bracket !");
	}
	else if (square_Bracket > 0) {
		printf("Error plenty square bracket !");
	}

	if ((curly_Bracket == 0) && (round_Bracket == 0) && (square_Bracket == 0)) {
		return true;
	}
	else {
		return false;
	}
}

bool checkErrorComments(char line[]) {
	int index = 0;
	bool inComments = false, outComments = false;

	while (line[index] != '\0') {
		if ((line[index] == '/') && (line[index + 1] == '*')) {
			inComments = true;
			outComments = false;
			index = index + 2;
			continue;
		}
		else if ((line[index] == '*') && (line[index + 1] == '/')) {
			outComments = true;
			index = index + 2;
		}
		++index;
	}

	if (!outComments) {
		printf("Error Missing ending Comments !");
		return false;
	}
	else {
		return true;
	}
}

void checkErrorQuotes(char line[]) {

}
