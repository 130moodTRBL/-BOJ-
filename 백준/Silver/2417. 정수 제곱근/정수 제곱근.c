#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	long long int n;
	scanf("%lld", &n);
	long long int i, j;
	long long int temp = 0;
	j = 3037000500;
	i = 0;
	
	while (i < j)
	{
		temp = (j + i) / 2;
		
		if (temp * temp >= n)
		{
			j = temp;
		}
		else
		{
			i = temp + 1;
		}
	}
	printf("%lld", j);
	//9223372036854775808

	return 0;
}