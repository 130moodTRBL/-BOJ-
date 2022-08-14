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

char board[101][101];
int vis[101][101];
int dis[101][101];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	queue<pair<int, int>> que;
	que.push({ 0,0 });
	vis[0][0] = 1;
	dis[0][0] = 1;
	while (!que.empty())
	{
		pair<int, int> cur = que.front();
		que.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = dx[dir] + cur.first;
			int ny = dy[dir] + cur.second;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				continue;
			}
			if (board[nx][ny] == '0' || vis[nx][ny]) {
				continue;
			}
			que.push({ nx,ny });
			vis[nx][ny] = 1;
			dis[nx][ny] = dis[cur.first][cur.second] + 1;
		}
	}
	cout << dis[n - 1][m - 1];




	return 0;
}