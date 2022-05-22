#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <cmath>

void star(int x, int y, int n)
{
	if ((x / n) % 3 == 1 && (y / n) % 3 == 1) {
		printf(" ");
	}
	else if (n / 3 == 0) {
		printf("*");
	}
	else {
		star(x, y, n / 3);
	}
	
}

int main()
{
	int n;
	int i, j;
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			star(i, j, n);
		}
		printf("\n");
	}
	

	return 0;
}
