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

int dp[1030][1030] = { 0 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	int i, j;
	int x1, x2, y1, y2;
	int x;
	cin >> n >> m;

	dp[1][1] = 1;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cin >> x;
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + x;
		}
	}

	while (m--)
	{
		cin >> x1 >> y1 >> x2 >> y2;

		cout << dp[x2][y2] - (dp[x1 - 1][y2] + dp[x2][y1 - 1]) + dp[x1 - 1][y1 - 1] << "\n";
	}





	return 0;
}