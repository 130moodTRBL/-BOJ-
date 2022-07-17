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

#define endl '\n'

using namespace std;
int dp[100001];

void sol()
{
	for (int i = 7; i <= 100000; i++) {
		dp[i] = ((dp[i - 2] + dp[i - 4]) % 1000000009 + dp[i - 6]) % 1000000009;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	int n;
	cin >> t;

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 2;
	dp[4] = 3;
	dp[5] = 3;
	dp[6] = 6;
	sol();
	while (t--)
	{
		cin >> n;
		cout << dp[n] << endl;
	}



	return 0;
}