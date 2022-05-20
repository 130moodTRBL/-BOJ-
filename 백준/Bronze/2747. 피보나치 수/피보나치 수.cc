#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <stdlib.h>
#include <algorithm>

long long arr[45];
int fibonacci(int n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 1;
	if (arr[n] != 0)
		return arr[n];

	return arr[n] = fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", fibonacci(n));

	return 0;
}
