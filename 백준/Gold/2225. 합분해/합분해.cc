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

long long dp[201][201];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	dp[0][0] = 1;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k <= j; k++) {
				dp[j][i] += dp[j - k][i - 1];
				dp[j][i] %= 1000000000;
			}
		}
	}
	cout << dp[n][k] % 1000000000;



	return 0;
}