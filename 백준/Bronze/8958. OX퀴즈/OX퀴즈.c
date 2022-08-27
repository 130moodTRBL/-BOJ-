#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n;
	int i, j;
	char s[80];
	int poi = 1;
	int sum = 0;

	scanf("%d", &n);
	
	for (i = 0; i < n; i++)
	{
		sum = 0;
		poi = 1;
		scanf("%s", s);
		int len = strlen(s);

		for (j = 0; j < len; j++)
		{
			if (s[j] == 'O')
			{
				sum += poi;
				poi++;
			}
			else if (s[j] == 'X')
			{
				poi = 1;
			}
		}
		printf("%d\n", sum);
	}
	


	
	
	return 0;
}
