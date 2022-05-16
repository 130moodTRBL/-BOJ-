#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>		
#include <time.h>

void hanoi(int n, int low, int mid, int end)
{
	if (n == 1)
	{
		printf("%d %d\n", low, end);
		return;
	}
	hanoi(n - 1, low, end, mid);
	printf("%d %d\n", low, end);
	hanoi(n - 1, mid, low, end);
	
}

int main()
{
	int n;
	int i;
	int cnt = 1;
	scanf("%d", &n);
	
	for (i = 0; i < n; i++)
	{
		cnt *= 2;
	}
	
	printf("%d\n", cnt - 1);
	hanoi(n, 1, 2, 3);

	

	return 0;
}