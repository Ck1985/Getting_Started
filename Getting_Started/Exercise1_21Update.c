#include <stdio.h>

#define TABINC 8

int main21Update() {
	int numTab, numSpace, position, c;
	numTab = 0;
	numSpace = 0;
	position = 1;

	for (position = 1; (c = getchar()) != EOF; ++position) {
		if (((c = getchar()) == ' ') || ((c = getchar()) == '\b')) {
			if ((position % TABINC) != 0) {
				++numSpace;
			}
			else {
				numSpace = 0;
				++numTab;
			}
		}
		else {
			for (; numTab > 0; --numTab) {
				putchar('\t');
			}

		}
	}
	return 0;
}