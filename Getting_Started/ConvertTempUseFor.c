#include<stdio.h>

mainFor() {
	int fah;

	for (fah = 0; fah <= 300; fah = fah + 20) {
		printf("%3d %6.1f\n", fah, (5.0 / 9.0)*(fah - 32));
	}
}