#include <stdio.h>

/* Count digits, whitespace, others */

mainArrays() {
	int c, i, nWhite, nOthers;
	int digits[10];

	nWhite = nOthers = 0;
	for (i = 0; i < 10; ++i) {
		digits[i] = 0;
	}
	while ((c = getchar()) != EOF) {
		if ((c >= '0') && (c <= '9')) {
			++digits[c - '0'];
		}
		else if ((c == ' ') || (c == '\t') || (c == '\n')) {
			++nWhite;
		} 
		else {
			++nOthers;
		}
	}
	printf("digits = ");
	for (i = 0; i < 10; ++i) {
		printf(" %d ", digits[i]);
	}
	printf("\n");
	printf("nWhite = %d, nOthers = %d\n", nWhite, nOthers);
}