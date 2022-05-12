#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <stdlib.h>
#include <algorithm>

int n, m;
int arr[8] = { 0, };
int flag[9] = { 0, };
void recursive(int level)
{
	int i;
	if (level == m)
	{
		for (i = 0; i < m; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}

	for (i = 0; i < n; i++)
	{
		if (level != 0)
		{
			if (flag[i + 1] == 0 && arr[level - 1] < i + 1)
			{
				arr[level] = i + 1;
				flag[i + 1] = 1;
				recursive(level + 1);
				arr[level] = 0;
				flag[i + 1] = 0;
			}
		}
		else
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

}

int main()
{
	scanf("%d %d", &n, &m);
	recursive(0);

	return 0;
}
