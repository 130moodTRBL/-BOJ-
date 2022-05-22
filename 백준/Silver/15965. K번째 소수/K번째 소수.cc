#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <cmath>

bool arr[7368790];
int prime[7368790];
void primeN()
{
	int i, j;
	int cnt = 1;
	for (i = 2; i * i <= 7368790; i++) {
		if (!arr[i]) {
			for (j = i * 2; j <= 7368790; j += i) {
				arr[j] = true;
			}
		}
	}

	for (i = 2; i <= 7368790; i++) {
		if (!arr[i]) {
			prime[cnt++] = i;
		}
	}

}

int main()
{
	int n;
	scanf("%d", &n);
	primeN();
	printf("%d", prime[n]);

	return 0;
}
