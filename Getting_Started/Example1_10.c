#include <stdio.h>

main1_10() {
	int c;

	c = getchar();
	
	while (c != EOF) {
		if (c == '\t') {
			putchar('\\');
			putchar('\\t');
		}
		else if (c == ' ') {
			putchar('\\');
			putchar('\\b');
		}
		else if (c == '\\') {
			putchar('\\');
			putchar('\\');
		}
		else {
			putchar(c);
		}
		c = getchar();
	}
}