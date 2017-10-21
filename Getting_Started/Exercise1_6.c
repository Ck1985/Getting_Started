#include <stdio.h>
#include <stdbool.h>

main1_6() {
	int c, check;
	bool boolean = true;

	while (boolean) {
		check = ((c = getchar()) != EOF);
		while (c != '\n') {
			if (check == 1) {
				printf("Value of check is: 1\n");
				break;
			}
			else {
				printf("Value of check is: 0\n");
				break;
			}
		}
	}
}