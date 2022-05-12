#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <stdlib.h>
#include <algorithm>

int n;
int arr[8] = { 0, };
int flag[9] = { 0, };
void recursive(int level)
{
	int i;
	if (level == n)
	{
		for (i = 0; i < n; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}

	for (i = 0; i < n; i++)
	{
		if (flag[i + 1] == 0)
		{
			arr[level] = i + 1;
			flag[i + 1] = 1;
			recursive(level + 1);
			arr[level] = 0;
			flag[i + 1] = 0;
		}
	}

}

int main()
{
	scanf("%d", &n);
	recursive(0);

	return 0;
}
