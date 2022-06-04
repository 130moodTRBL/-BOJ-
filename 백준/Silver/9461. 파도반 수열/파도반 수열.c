#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long arr[101];

long long pado(int n)
{
	if (n <= 3)
		return 1;
	if (arr[n])
		return arr[n];

	return arr[n] = pado(n - 2) + pado(n - 3);
}

int main()
{
	int t, n;

	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;

	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		printf("%lld\n", pado(n));
	}

	return 0;
}