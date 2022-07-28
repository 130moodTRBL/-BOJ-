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
#include <tuple>

#define endl '\n'
using namespace std;

int dp[1001][1001];
string a, b;

void sol(int x, int y)
{
	if (dp[x][y] == 0) {
		return;
	}

	if (a[x - 1] == b[y - 1]) {
		sol(x - 1, y - 1);
		cout << a[x - 1];
	}
	else {
		if (dp[x - 1][y] > dp[x][y - 1]) {
			sol(x - 1, y);
		}
		else {
			sol(x, y - 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int temp = -1;
	cin >> a >> b;

	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			if (a[i] == b[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else {
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
			}
		}
	}

	int x, y;
	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (temp < dp[i][j]) {
				temp = dp[i][j];
				x = i;
				y = j;
			}
		}
	}
	cout << temp << endl;
	if (temp != 0) {
		sol(x, y);
	}



	return 0;
}