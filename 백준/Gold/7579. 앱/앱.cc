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
#include <map>
#include <unordered_map>

#define endl '\n'
using namespace std;

int app[101];
int cost[101];
int dp[101][100001];
int sum = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> app[i];
	}

	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
		sum += cost[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (j - cost[i] < 0) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + app[i]);
			}
		}
	}
	
	vector<int> arr;
	for (int i = 1; i <= sum; i++) {
		if (dp[n][i] >= m) {
			cout << i;
			exit(0);
		}
	}
	//cout << dp[n][m];




	return 0;
}