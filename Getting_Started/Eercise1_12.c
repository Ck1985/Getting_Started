#include <stdio.h>

#define IN 1
#define OUT 0

main1_12() {
	int c, nc, nl, nw, nt, ns, state;

	nc = nl = nw = nt = ns = 0;
	state = OUT;

	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n') {
			++nl;
		}
		if (c == ' ') {
			++ns;
		}
		if (c == '\t') {
			++nt;
		}
		if ((c == ' ') || (c == '\t') || (c == '\n')) {
			state = OUT;
		} 
		else if (state == OUT) {
			state = IN;
			ns = nt = 0;
			++nw;
		}
		if (state == IN) {
			putchar(c);
		}
		else if ((ns == 1) || (nt == 1)) {
			putchar('\n');
		}
	}
}