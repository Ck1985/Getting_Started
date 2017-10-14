#include<stdio.h>

mainConvertTemp() {
	/* Fahrenheit - Celsius table
		for fah = 0, 20, 40, ..., 300
	*/
	float fah, cel;
	int step, lower, upper;

	step = 20;
	lower = 0;
	upper = 300;
	fah = lower;
	while (fah <= upper) {
		cel = (5.0 / 9.0)*(fah - 32);
		printf("%3.0f %6.2f\n", fah, cel);
		fah = fah + step;
	}
}