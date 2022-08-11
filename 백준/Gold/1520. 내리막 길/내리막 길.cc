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

int board[501][501];
int dp[501][501];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;

int dfs(int x, int y)
{
	if (x == n - 1 && y == m - 1) {
		return 1;
	}
	if (dp[x][y] != -1) {
		return dp[x][y];
	}
	dp[x][y] = 0;
	for (int dir = 0; dir < 4; dir++) {
		int nx = dx[dir] + x;
		int ny = dy[dir] + y;
		if (nx < 0 || nx > n || ny < 0 || ny > m) {
			continue;
		}
		if (board[x][y] > board[nx][ny]) {
			dp[x][y] = dp[x][y] + dfs(nx, ny);
		}
	}

	return dp[x][y];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			dp[i][j] = -1;
		}
	}
	//dp[0][0] = 0;
	cout << dfs(0, 0);




	return 0;
}