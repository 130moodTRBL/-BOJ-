#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int compare(const void *a , const void *b)
{
	int n1 = *(int*)a;
	int n2 = *(int*)b;

	if (n1 < n2)
		return -1;
	else if (n1 > n2)
		return 1;
	return 0;
}

int main()
{
	int n;
	int arr[1000000] = { 0, };
	int i;
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	qsort(arr, n, sizeof(int), compare);

	for (i = 0; i < n; i++)
	{
		printf("%d\n", arr[i]);
	}

	
	
	return 0;
}
