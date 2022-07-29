#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <queue>

#define endl '\n'
using namespace std;

int arr[2001];
int dp[2001][2001];

void sol(int n)
{
	for (int i = 2; i <= n - 1; i++) {
		for (int j = 1; j <= n - i; j++) {
			if (arr[j] == arr[i + j] && dp[j + 1][i + j - 1]) {
				dp[j][i + j] = 1;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	cin >> m;

	for (int i = 1; i <= n; i++) {
		dp[i][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		if (arr[i] == arr[i - 1]) {
			dp[i - 1][i] = 1;
		}
	}
	sol(n);
	int s, e;
	while (m--)
	{
		cin >> s >> e;
		cout << dp[s][e] << endl;
	}




	return 0;
}