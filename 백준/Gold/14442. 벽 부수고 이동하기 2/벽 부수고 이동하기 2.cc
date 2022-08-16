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

char board[1001][1001];
int vis[1001][1001][11];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
		}
	}

	queue<tuple<int, int, int>> que;
	que.push({ 1,1,k });
	for (int i = 0; i <= k; i++) {
		vis[1][1][i] = 1;
	}

	int x, y, wall;
	while (!que.empty())
	{
		tie(x, y, wall) = que.front();
		que.pop();
		if (x == n && y == m) {
			cout << vis[n][m][wall];
			exit(0);
		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];	
			if (nx <= 0 || nx > n || ny <= 0 || ny > m) {
				continue;
			}
			if (board[nx][ny] == '1' && vis[nx][ny][wall - 1] == 0 && wall > 0) {
				que.push({ nx,ny,wall - 1 });
				vis[nx][ny][wall - 1] = vis[x][y][wall] + 1;
				//dis[nx][ny] = dis[x][y] + 1;
			}
			if (board[nx][ny] == '0' && vis[nx][ny][wall] == 0) {
				que.push({ nx,ny,wall });
				vis[nx][ny][wall] = vis[x][y][wall] + 1;
				//dis[nx][ny] = dis[x][y] + 1;
			}
		}
	}
	cout << -1;




	return 0;
}