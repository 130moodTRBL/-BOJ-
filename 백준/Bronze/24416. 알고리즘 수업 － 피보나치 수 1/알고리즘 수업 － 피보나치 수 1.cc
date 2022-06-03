#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <cmath>

int arr[45];
int DPcnt = 0;
int cnt = 0;

int fibonacci(int n)
{
	cnt++;
	if (n == 1 || n == 2)
		return 1;
	return fibonacci(n - 1) + fibonacci(n - 2);
}

int DPfibonacci(int n)
{
	for (int i = 3; i <= n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	return arr[n];
}

int main()
{
	int n;

	arr[1] = 1;
	arr[2] = 1;

	scanf("%d", &n);
	
	printf("%d %d\n", fibonacci(n), n-2);

	return 0;
}
