#include <stdio.h>

mainCC1() {
	long nc;
	
	nc = 0;
	while (getchar() != EOF) {
		++nc;
	}
	printf("%1d", nc);
}