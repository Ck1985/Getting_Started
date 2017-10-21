#include <stdio.h>

/* Program counts backspace, tab, newline */

main1_8() {
	int c;
	int tabCount, spaceCount, newlineCount;

	tabCount = 0;
	spaceCount = 0;
	newlineCount = 0;

	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			++tabCount;
		}
		else if (c == ' ') {
			++spaceCount;
		}
		else if (c == '\n') {
			++newlineCount;
		}
	}
	printf("Count of Tab: %d\n", tabCount);
	printf("Count of BackSpace: %d\n", spaceCount);
	printf("Count of newLine: %d\n", newlineCount);
}