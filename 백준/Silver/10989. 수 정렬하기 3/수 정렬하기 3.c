#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	int n, num;
	int cnt[10001] = { 0, };
	int i, j;
	int max = -1;
	
	scanf("%d", &n);
	for (i = 0; i < n; i ++)
	{
		scanf("%d", &num);
		cnt[num]++;
		if (num > max)
			max = num;
	}
	for (i = 0; i < max+1; i++)
	{
		if (cnt[i] != 0)
		{
			for (j = 0; j < cnt[i]; j++)
			{
				printf("%d\n", i);
			}
		}
	}



	
	return 0;
}
