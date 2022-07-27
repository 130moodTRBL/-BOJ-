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

#define X first
#define Y second

char board[1001][1001];
char temp[1001][1001];
int vis[1001][1001][2];
int dis[1001][1001];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int ans[1001];

void fill()
{
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			vis[i][j][0] = 0;
			vis[i][j][1] = 0;
			dis[i][j] = 0;
			temp[i][j] = board[i][j];
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	int pos = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
		}
	}
	
	queue<tuple<int, int, int>> que;
	que.push({ 1,1,1 });
	vis[1][1][0] = 1;
	vis[1][1][1] = 1;
	dis[1][1] = 1;
	while (!que.empty())
	{
		int x, y, wall;
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
			
			if (board[nx][ny] == '1' && wall == 1) {
				que.push({ nx,ny,0 });
				vis[nx][ny][wall - 1] = vis[x][y][wall] + 1;
			}
			if (board[nx][ny] == '0' && vis[nx][ny][wall] == 0) {
				que.push({ nx,ny,wall });
				vis[nx][ny][wall] = vis[x][y][wall] + 1;
			}

		}
	}
	cout << -1;

	


	return 0;
}