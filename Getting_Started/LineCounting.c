#include <stdio.h>

mainLC() {
	int c, nl;
	nl = 0;

	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			++nl;
		}
	}
	printf("Count of line: %d\n", nl);
}