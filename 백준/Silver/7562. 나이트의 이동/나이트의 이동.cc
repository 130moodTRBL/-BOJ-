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

char board[301][301];
int vis[301][301];
int dis[301][301];
int dx[8] = { 2,1,-1,-2,-2,-1,1,2 };
int dy[8] = { 1,2,2,1,-1,-2,-2,-1 };

void fill()
{
	for (int i = 0; i < 301; i++) {
		for (int j = 0; j < 301; j++) {
			vis[i][j] = 0;
			dis[i][j] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		fill();
		int n;
		cin >> n;
		int startX, startY, lastX, lastY;
		cin >> startX >> startY;
		cin >> lastX >> lastY;
		if (startX == lastX && startY == lastY) {
			cout << 0 << endl;
			continue;
		}
		queue<pair<int, int>> que;
		que.push({ startX,startY });
		vis[startX][startY] = 1;
		while (!que.empty())
		{
			pair<int, int> cur = que.front();
			que.pop();
			if (cur.first == lastX && cur.second == lastY) {
				cout << dis[cur.first][cur.second] << endl;
				break;
			}
			for (int dir = 0; dir < 8; dir++) {
				int nx = dx[dir] + cur.first;
				int ny = dy[dir] + cur.second;
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
					continue;
				}
				if (vis[nx][ny]) {
					continue;
				}
				que.push({ nx,ny });
				vis[nx][ny] = 1;
				dis[nx][ny] = dis[cur.first][cur.second] + 1;
			}
		}
	}




	return 0;
}