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

int arr[1001][1001];
int dp[1001][1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	int cnt = 0;
	int res = 0;
	cin >> n >> m;
	int temp = min(n, m);
	string s;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			arr[i][j + 1] = s[j] - '0';
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] != 0) {
				arr[i][j] = min(min(arr[i - 1][j], arr[i][j - 1]), arr[i - 1][j - 1]) + 1;
				res = max(arr[i][j], res);
			}
		}
	}
	cout << res * res;


	return 0;
}