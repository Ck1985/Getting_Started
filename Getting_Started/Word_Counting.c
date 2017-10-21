#include <stdio.h>

#define IN 1    /*Inside a word*/
#define OUT 0   /*Outside a word*/

main() {
	int c, nl, nw, nc, state;

	c = getchar();
	nl = nw = nc = 0;
	state = OUT;
	
	while (c != EOF) {
		++nc;
		if (c == '\n') {
			++nl;
		}
		if ((c == '\t') || (c == ' ') || (c == '\n')) {
			state = OUT;
		}
		else if (state == OUT) {
			state = IN;
			++nw;
		}
		c = getchar();
	}

	/*state = OUT;
	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n') {
			++nl;
		}
		if ((c == '\t') || (c == ' ') || (c == '\n')) {
			state = OUT;
		}
		else if (state == OUT) {
			state = IN;
			++nw;
		}
	}*/
	printf("The Line: %d\nThe Word: %d\nThe Character: %d\n", nl, nw, nc);
}