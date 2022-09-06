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

int dp[1001][1001];
int arr[1001][1001];
int ans = 1900000000;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}
	
	for (int rgb = 0; rgb < 3; rgb++) {
		for (int i = 0; i < 3; i++) {
			if (i == rgb) {
				dp[1][rgb] = arr[1][rgb];
			}
			else {
				dp[1][i] = 1900000000;
			}
		}

		for (int i = 2; i <= n; i++) {
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
		}

		int temp = 1900000000;
		for (int i = 0; i < 3; i++) {
			if (i == rgb) {
				continue;
			}
			temp = min(temp, dp[n][i]);
		}

		ans = min(temp, ans);
	}
	cout << ans;




	return 0;
}