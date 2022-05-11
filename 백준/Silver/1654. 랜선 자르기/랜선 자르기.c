#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int arr[10000] = { 0, };
int main()
{
	long long int k, n, i;

	scanf("%lld %lld", &k, &n);

	for (i = 0; i < k; i++)
	{
		scanf("%d", &arr[i]);
	}

	long long int low, mid, hig;
	long long int cnt = 0;
	low = 0;
	hig = 2147483647;
	while (low < hig)
	{
		cnt = 0;
		mid = ceil((low + hig) / 2.0);
		for (i = 0; i < k; i++)
		{
			cnt += arr[i] / mid;
		}
		if (cnt < n)
		{
			hig = mid - 1;
		}
		else
		{
			low = mid;
		}
	}
	printf("%lld", hig);

	return 0;
}