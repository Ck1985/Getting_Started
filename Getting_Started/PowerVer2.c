#include <stdio.h>

int main() {
	return 0;
}

int power(int base, int n) {
	int p;

	for (p = 1; n > 0; --n) {
		p = p * base;
	}
	return p;
}