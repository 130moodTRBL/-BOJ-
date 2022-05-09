#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int n, i;
	int diff, x, y;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &x, &y);

		diff = (int)sqrt(y - x);

		if ((y - x) == diff * diff)
		{
			printf("%d\n", 2 * diff - 1);
		}
		else if ((y - x) <= diff * diff + diff)
		{
			printf("%d\n", 2 * diff);
		}
		else
		{
			printf("%d\n", 2 * diff + 1);
		}
	}




	return 0;
}