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

char board[101][101];
int dis[101][101];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
const int INF = 9999999;

void fill()
{
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			dis[i][j] = INF;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	std::cout.tie(0);

	int n, m;
	char a, b;
	int ans = 9999999;
	fill();
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a;
			board[i][j] = a;
		}
	}
	queue<pair<int, int>> que;
	que.push({ 1,1 });
	dis[1][1] = 0;
	while (!que.empty())
	{
		pair<int, int> cur = que.front();
		que.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 1 || nx > n || ny < 1 || ny > m) {
				continue;
			}
			if (board[nx][ny] == '1') {
				if (dis[nx][ny] > dis[cur.first][cur.second] + 1) {
					dis[nx][ny] = dis[cur.first][cur.second] + 1;
					que.push({ nx,ny });
				}
			}
			else {
				if (dis[nx][ny] > dis[cur.first][cur.second]) {
					dis[nx][ny] = dis[cur.first][cur.second];
					que.push({ nx,ny });
				}
			}
		}
	}
	if (dis[n][m] == INF) {
		std::cout << 0;
	}
	else {
		std::cout << dis[n][m];
	}
	




	return 0;
}