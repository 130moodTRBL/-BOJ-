#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <stdlib.h>
#include <algorithm>

void recurse(int n)
{
	int i;
	for (i = 2; i <= n; i++)
	{
		if (n % i == 0)
		{
			printf("%d\n", i);
			return recurse(n / i);
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	recurse(n);

	return 0;
}
