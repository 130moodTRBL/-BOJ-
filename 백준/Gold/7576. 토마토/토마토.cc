#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <queue>
#include <stack>

#define X first
#define Y second

using namespace std;

int board[1000][1000];
int vis[1000][1000];
int dis[1000][1000];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<int, int>> que;
	int n, m, k;
	int i, j;
	int cnt = 0;
	int max = 0;
	cin >> m >> n;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				que.push({ i,j });
				vis[i][j] = 1;
			}
		}
	}

	while (!que.empty())
	{
		pair<int, int> cur = que.front();
		que.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				continue;
			}
			if (vis[nx][ny] || board[nx][ny] == -1) {
				continue;
			}
			vis[nx][ny] = 1;
			dis[nx][ny] = dis[cur.X][cur.Y] + 1;
			que.push({ nx,ny });
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (dis[i][j] == 0 && board[i][j] == 0) {
				cout << -1;
				exit(0);
			}
			if (dis[i][j] > max)
				max = dis[i][j];
		}
	}
	cout << max;
	

	


	return 0;
}