#include <stdio.h>
#include <stdbool.h>

/* Histogram of length Words 
   Bar Vertical and Bar Horizonal */

#define OUT 0
#define IN 1

main1_13Ver2() {
	int c, state, nw, lenWord, index;
	int lenFactArray[16];

	state = OUT;
	nw = lenWord = index = 0;

	for (int i = 0; i < 16; ++i) {
		lenFactArray[i] = 0;
	}

	printf("Please input some character, then press Ctr + Z\n");

	while ((c = getchar()) != EOF) {
		if ((c == ' ') || (c == '\t') || (c == '\n')) {
			state = OUT;
			lenFactArray[index] = lenWord;
			index++;
			lenWord = 0;
		}
		else if (state == OUT) {
			state = IN;
			++nw;
		}
		if (state == IN) {
			++lenWord;
		}
	}
	for (int i = 0; i < 16; ++i) {
		printf("%d ", lenFactArray[i]);
	}
	printf("\n");

	printf("Horizontal Histogram:\n");

	printf("\n");
	printf("  Length | Graphic\n");

	for (int i = 1; i < 17; i++) {          
		if (i == 16) {
			printf("%6c%d | ", '>', 15);
			for (int j = 0; j < 16; j++) {  
				if (i <= lenFactArray[j]) {
					printf("%c ", '+');
				}
			}
			printf("\n");
			break;
		}
		else {
			printf("%8d | ", i);
		}
		for (int j = 0; j < 16; j++) {
			if (i == lenFactArray[j]) {
				printf("%c ", '+');
			}
		}
		printf("\n");
	}

	printf("\n");

	printf("Vertical Histogram:\n");

	int verticalArray[16];

	printf("\n");

	for (int i = 1; i < 16; i++) {
		int count = 0;
		for (int j = 0; j < 16; j++) {
			if (i == lenFactArray[j]) {
				count++;
			}
		}
		verticalArray[i] = count;
	}

	for (int i = 16; i > 0; --i) {
		int head, tail, count;
		head = tail = -1;
		count = 0;
		bool newLine = false;
		for (int j = 0; j < 16; ++j) {
			if (i <= verticalArray[j]) {
				if (count == 0) {
					printf("%d |", i);
				}
				count++;
				tail = j;				
				if (head == -1) {
					for (int k = head; k < tail - 1; ++k) {
						printf("  ");
					}
					printf("+ ");
				}
				else if (head == tail - 1) {
					printf("+ ");
				}
				else {
					for (int k = head; k < tail - 1; ++k) {
						printf("  ");
					}
					printf("+ ");
				}
				head = tail;
				newLine = true;
			} 
		}
		if (newLine) {
			printf("\n");
		}
	}
	printf("--------------------------------------------\n");
	printf("     ");
	for (int i = 1; i < 17; i++) {
		if (i == 16) {
			printf("%c%d", '>', 15);
		}
		else {
			printf("%d ", i);
		}
	}

	printf("\n");
}

