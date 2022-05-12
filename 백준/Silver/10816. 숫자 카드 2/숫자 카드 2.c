#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int arr[500000];
int len[500000];

int static compare(const void* first, const void* second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}

int lowerBound(int n, int x)
{
	int low, mid, hig;

	low = 0;
	hig = n - 1;
	while (low < hig)
	{
		mid = (low + hig) / 2;
		if (arr[mid] < x)
			low = mid + 1;
		else
			hig = mid;
	}
	if (arr[hig] != x)
		return 0;

	return hig;
}

int upperBound(int n, int x)
{
	int low, mid, hig;

	low = 0;
	hig = n;
	while (low < hig)
	{
		mid = (low + hig) / 2;
		if (arr[mid] <= x)
			low = mid + 1;
		else
			hig = mid;
	}
	if (arr[hig-1] != x)
		return 0;
	return hig;
}

int main()
{
	int n, m, x;
	int i;
	int cnt;
	
	cnt = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		cnt++;
	}
	qsort(arr, cnt, sizeof(int), compare);

	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d", &x);
		len[i] = upperBound(n, x) - lowerBound(n, x);
	}

	for (i = 0; i < m; i++)
	{
		printf("%d ", len[i]);
	}


	return 0;
}
