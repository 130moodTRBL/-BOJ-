#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <cmath>

using namespace std;


int main()
{
	long long n, m;
	scanf("%lld %lld", &n, &m);
	printf("%lld\n", abs(n - m));

	return 0;
}