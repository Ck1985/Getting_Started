#include <stdio.h>

mainCC2() {
	double nc;

	for (nc = 0; getchar() != EOF; ++nc);
	printf("%.0f", nc);
}