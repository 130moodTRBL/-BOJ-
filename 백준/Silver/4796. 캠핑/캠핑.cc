#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <cmath>

using namespace std;


int main()
{
	int l, p, v;
	int cnt = 0;
	long long sum = 0;
	long long temp;

	scanf("%d %d %d", &l, &p, &v);
	while (l != 0 && p != 0 && v != 0)
	{
		sum = 0;
		cnt++;
		temp = v / p;
		sum += (temp * l) + min(v % p, l);
		printf("Case %d: %lld\n", cnt, sum);
		scanf("%d %d %d", &l, &p, &v);
	}
	

	return 0;
}