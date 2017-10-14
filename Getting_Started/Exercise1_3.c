#include<stdio.h>

mainExe1_3() {
	/* Fahrenheit-Celsius table
	  for fah = 0, 20, 40, ...., 300*/
	char chuoi[] = "----This is Fahrenheit Celsius Table-----\n";
	printf("%8s", chuoi);
	float fah, cel;
	int step, lower, upper;
	lower = 0;
	upper = 300;
	step = 20;
	fah = lower;
	while (fah <= upper) {
		cel = (5.0 / 9.0) * (fah - 32);
		printf("%3.0f %6.1f\n", fah, cel);
		fah = fah + step;
	}
}