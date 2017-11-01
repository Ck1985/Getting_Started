#include <stdio.h>

/* Print Histogram of Frequency of difference character */

main1_14() {
	printf("Print Histogram of frequence of difference character \n");
	
	int valueChar[95];
	int totalChar[95];
	int c, start = 32;

	for (int i = 0; i < 95; i++) {
		valueChar[i] = start++;
	}

	for (int i = 0; i < 95; i++) {
		totalChar[i] = 0;
	}
	
	printf("\n");

	while ((c = getchar()) != EOF) {
		for (int i = 0; i < 95; i++) {
			if (c == valueChar[i]) {
				totalChar[i]++;
			}
		}
	}
	

	printf("Histogram of difference character:\n");
	printf("\n");
	// Show Histogram
	for (int i = 0; i < 95; i++) {
		if (totalChar[i] != 0) {
			printf("%c |", valueChar[i]);
			for (int j = 0; j < totalChar[i]; j++) {
				printf("%c ", '+');
			}
			printf("\n");
		}
	}

	printf("\n");
}