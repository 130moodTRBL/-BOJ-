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

int arr[50001];
int sum[50001] = { 0 };
int dp[50001][4] = { 0 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	int temp = -1;
	int s = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum[i] = arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}
	cin >> k;

	for (int i = 1; i <= 3; i++) {
		for (int j = k; j <= n; j++) {
			s = sum[j] - sum[j - k];
			dp[j][i] = max(dp[j - 1][i], dp[j - k][i - 1] + s);
		}
	}
	cout << dp[n][3];
	



	return 0;
}