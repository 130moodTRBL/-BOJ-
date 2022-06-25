#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <stack>
#include <queue>
#include <utility>

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

	dp[0] = 1;
	for (i = 0; i < n; i++) {
		for (j = coin[i]; j <= k; j++) {
			dp[j] = dp[j - coin[i]] + dp[j];
			//cout << j << " is " << dp[j] << endl;
		}
	}
	cout << dp[k];




	return 0;
}