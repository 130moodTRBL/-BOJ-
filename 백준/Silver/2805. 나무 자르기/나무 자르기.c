#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

long long arr[1000000] = { 0, };
int main()
{
	long long n, m, i;
	long long cnt = 0;
	scanf("%lld %lld", &n, &m);

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &arr[i]);
	}

	long long low = 0;
	long long hig = 2000000000;
	long long mid;

	while (low < hig)
	{
		cnt = 0;
		mid = (low + hig) / 2 + 1;
		for (i = 0; i < n; i++)
		{
			if (arr[i] - mid > 0)
			{
				cnt += arr[i] - mid;
			}
		}
		if (cnt >= m)
		{
			low = mid;
		}
		else
		{
			hig = mid - 1;
		}
	}
	printf("%lld", hig);


	return 0;
}