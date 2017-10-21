#include <stdio.h>

/* Program copy its input to its output.... */

main1_9() {
	printf("Program copy its input to its output....\n");

	int c;
	int blankCount;

	blankCount = 0;
	c = getchar();
	// while ((c = getchar() != EOF){.....}
	while (c != EOF) {
		if (c == ' ') {
			++blankCount;
			if (blankCount > 1) {
				putchar(c);
				blankCount = 0;
			}
		}
		else {
			putchar(c);
		}
		c = getchar();
	}
}