#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

int arr[100001];
int dp[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	for (int i = 0; i <= 10000; i++) {
		dp[i] = -1;
	}

	dp[0] = 0;
	dp[2] = 1;
	dp[3] = -1;
	dp[4] = 2;
	dp[5] = 1;
	dp[6] = 3;
	dp[7] = 2;
	dp[8] = 4;
	for (int i = 9; i <= n; i++) {
		if (dp[i - 2] != -1 && dp[i - 5] != -1) {
			dp[i] = min(dp[i - 2] + 1, dp[i - 5] + 1);
		}
	}
	cout << dp[n];



	return 0;
}