#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int arrN[100000] = { 0, };
int compare(const void* a, const void* b)
{
	return *(int*)a > *(int*)b ? 1 : (*(int*)a < *(int*)b ? -1 : 0);
}

int lowerBound(int n, int x)
{
	int low, mid, hig;
	low = 0;
	hig = n;
	while (low < hig)
	{
		mid = (low + hig) / 2;
		if (arrN[mid] < x)
			low = mid + 1;
		else
			hig = mid;
	}
	return low;
}

int main()
{
	int n, m, x;
	int i;
	int flag;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arrN[i]);
	}
	qsort(arrN, n, sizeof(int), compare);

	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d", &x);
		flag = lowerBound(n, x);
		if (arrN[flag] == x && flag < n)
			printf("%d\n", 1);
		else
			printf("%d\n", 0);
	}


	return 0;
}
