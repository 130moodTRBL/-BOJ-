#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <cmath>

int arr[1000001];

int makingOne(int n)
{
	arr[1] = 0;
	for (int i = 2; i <= n; i++) {
		arr[i] = arr[i - 1] + 1;
		if (i % 3 == 0) {
			arr[i] = std::min(arr[i], arr[i / 3] + 1);
		}
		if (i % 2 == 0) {
			arr[i] = std::min(arr[i], arr[i / 2] + 1);
		}
	}
	return arr[n];
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", makingOne(n));

	return 0;
}
