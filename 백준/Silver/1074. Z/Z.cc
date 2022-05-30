#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <cmath>

int n, r, c;
int ans = 0;

void prZ(int n, int m, int r, int c)
{
	if (n == 0) {
		return;
	}
	
	//1
	if (r < (1 << n) / 2 && c < (1 << n) / 2) {
		ans += (m / 4) * 0;
		prZ(n - 1, (1 << (n - 1)) * (1 << (n - 1)), r % (1 << (n - 1)), c % (1 << (n - 1)));
	}
	//2
	else if (r < (1 << n) / 2 && c >= (1 << n) / 2) {
		ans += (m / 4) * 1;
		prZ(n - 1, (1 << (n - 1)) * (1 << (n - 1)), r % (1 << (n - 1)), c % (1 << (n - 1)));
	}
	//3
	else if (r >= (1 << n) / 2 && c < (1 << n) / 2) {
		ans += (m / 4) * 2;
		prZ(n - 1, (1 << (n - 1)) * (1 << (n - 1)), r % (1 << (n - 1)), c % (1 << (n - 1)));
	}
	//4
	else if (r >= (1 << n) / 2 && c >= (1 << n) / 2) {
		ans += (m / 4) * 3;
		prZ(n - 1, (1 << (n - 1)) * (1 << (n - 1)), r % (1 << (n - 1)), c % (1 << (n - 1)));
	}
}

int main()
{
	int m;
	scanf("%d %d %d", &n, &r, &c);
	m = 1 << n;

	prZ(n, m * m, r, c);
	printf("%d\n", ans);

	return 0;
}
