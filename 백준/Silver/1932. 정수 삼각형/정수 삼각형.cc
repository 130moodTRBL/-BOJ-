#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <cmath>

using namespace std;

int arr[501][501];
int dp[501][501];
int main()
{
	int n, val;
	int pos = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	dp[0][0] = arr[0][0];
	val = arr[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][0] + arr[i][j];
			}
			else if (i == j) {
				dp[i][j] = dp[i - 1][j - 1] + arr[i][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + arr[i][j];
			}
			//printf("dp[%d][%d] : %d\n", i, j, dp[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		if (val < dp[n - 1][i]) {
			val = dp[n - 1][i];
		}
	}
	printf("%d", val);
	

	return 0;
}