#include <stdio.h>

int mainVer2() {
	return 0;
}

int powerVer2(int base, int n) {
	int p;

	for (p = 1; n > 0; --n) {
		p = p * base;
	}
	return p;
}