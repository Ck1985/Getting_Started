#include <stdio.h>

/* Convert Temperature by using functions */

float convertFahToCel(float fah);

int main1_15() {
	float fah = 40, cel;
	cel = convertFahToCel(fah);
	printf("%3.0f %6.2f\n", fah, cel);
	return 0;
}

float convertFahToCel(float fah) {
	float cel;
	cel = (5.0 / 9.0) * (fah - 32);
	return cel;
}