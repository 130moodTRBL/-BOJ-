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
#include <cmath>

using namespace std;

int dp[101][100001];
int w[100001];
int v[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	int i, j;
	vector<pair<int, int>> arr;

	cin >> n >> k;
	for (i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= k; j++) {
			if (j - w[i] >= 0) {
				dp[i][j] = max(dp[i - 1][j - w[i]] + v[i], dp[i - 1][j]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[n][k];



	return 0;
}