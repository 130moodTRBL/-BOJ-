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
int dp[1001][1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string a, b;
	int i, j;
	int temp = -1;
	cin >> a >> b;
	for (i = 0; i < a.length(); i++) {
		for (j = 0; j < b.length(); j++) {
			if (a[i] == b[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else {
				dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
			}
		}
	}
	for (i = 1; i <= 1000; i++) {
		for (j = 1; j <= 1000; j++) {
			temp = max(temp, dp[i][j]);
		}
	}
	cout << temp;



	return 0;
}