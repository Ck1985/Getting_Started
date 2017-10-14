#include<stdio.h>

main1_4() {
	/* Fahrenheit celcius table
	   for fah = 0, 20, 40, ...., 300 */
	float fah, cel;
	int step, lower, upper;

	lower = -20;
	upper = 35;
	step = 5;
	cel = lower;

	while (cel <= upper) {
		fah = ((9.0 * cel) / 5.0) + 32;
		printf("%3.0f %6.0f\n", cel, fah);
		cel = cel + step;
	}
}