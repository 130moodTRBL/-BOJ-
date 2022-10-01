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
#include <set>
#include <deque>

#define endl '\n'
using namespace std;

int arr[101];
long long dp[101][101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	dp[1][arr[1]] = 1;
	for (int i = 2; i < n; i++) {
		for (int j = 0; j <= 20; j++) {
			if (j + arr[i] <= 20) {
				dp[i][j + arr[i]] += dp[i - 1][j];
			}
			if (j - arr[i] >= 0) {
				dp[i][j - arr[i]] += dp[i - 1][j];
			}
		}
	}
	cout << dp[n - 1][arr[n]];



	return 0;
}