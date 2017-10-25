#include <stdio.h>

/* Histogram of lenght Words 
   Bar Horizontal */

#define IN 1
#define OUT 0

main() {
	int c, state, nw, lenWord;
	int lenArray[100];

	state = OUT;
	nw = 0;
	lenWord = 0;

	for (int i = 0; i < 100; ++i) {
		lenArray[i] = 0;
	}

	while ((c = getchar()) != EOF) {
		if ((c == ' ') || (c == '\t') || (c == '\n')) {
			state = OUT;
			lenWord = 0;
		}
		else if (state == OUT) {
			state = IN;
			++nw;
		}
		if (state == IN) {
			++lenWord;
			lenArray[nw - 1] = lenWord;
		}
	}

	printf("lenArray = ");
	for (int i = 0; i < nw; ++i) {
		printf("%d ", lenArray[i]);
	}
}