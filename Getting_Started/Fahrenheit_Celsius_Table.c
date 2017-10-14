#include <stdio.h>

mainFah() {
	/* Print Fahrenheit-Celsius table
	for Fah = 0, 20, ....., 300 */

	int fah, cel;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fah = lower;
	while (fah <= upper) {
		cel = (5 * (fah - 32)) / 9;
		//printf("%d\t%d\n", fah, cel);
		printf("%5d %8d\n", fah, cel);
		fah = fah + step;
	}
}