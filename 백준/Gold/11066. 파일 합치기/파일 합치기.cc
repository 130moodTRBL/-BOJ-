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

int arr[501];
int sum[501];
int dp[501][501];

const int INF = 1999999999;

void fill()
{
	for (int i = 0; i < 501; i++) {
		for (int j = 0; j < 501; j++) {
			dp[i][j] = INF;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			sum[i] = sum[i - 1] + arr[i];
		}
		fill();
		for (int i = 0; i <= n; i++) {
			dp[i][i] = 0;
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n - i; j++) {
				for (int k = j; k <= j + i; k++) {
					int s = sum[i + j] - sum[j - 1];
					dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + s);
				}
			}
		}
		cout << dp[1][n] << endl;
	}



	return 0;
}