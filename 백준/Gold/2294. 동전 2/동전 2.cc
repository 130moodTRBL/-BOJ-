#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;
int coin[10001];
int dp[10001];

int main() 
{
	int n, k;
	int i, j;
	cin >> n >> k;
	for (i = 0; i < n; i++) {
		cin >> coin[i];
	}

	for (i = 0; i <= k; i++) {
		dp[i] = 10001;
	}
	dp[0] = 0;
	
	for (i = 0; i < n; i++) {
		for (j = coin[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}

	if (dp[k] == 10001) {
		cout << -1;
	}
	else {
		cout << dp[k];
	}
	

	return 0;
}