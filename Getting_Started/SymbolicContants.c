#include<stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

/*Print Fahrenheit - Celsius Table */
main() {
	int fah;

	for (fah = LOWER; fah <= UPPER; fah = fah + STEP) {
		printf("%3d %6.1f\n", fah, (5.0 / 9.0)*(fah - 32));
	}
}