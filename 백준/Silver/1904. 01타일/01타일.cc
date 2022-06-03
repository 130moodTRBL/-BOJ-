#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <cmath>

long long arr[1000001];

long long tile(int n)
{
	if (n <= 2)
		return n;

	if (arr[n])
		return arr[n];

	return arr[n] = (tile(n - 1) + tile(n - 2)) % 15746;
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%lld\n", tile(n));

	return 0;
}