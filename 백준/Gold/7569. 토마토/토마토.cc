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

int board[101][101][101];
int vis[101][101][101];
int dis[101][101][101];
int dx[] = { 0,1,0,-1,0,0 };
int dy[] = { 1,0,-1,0,0,0 };
int dz[] = { 0,0,0,0,1,-1 };

void P(int n, int m, int h)
{
	cout << "===============" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < h; k++) {
				cout << board[i][j][k] << " ";
			}
		}
	}
	cout << "================" << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, h;
	queue<tuple<int, int, int>> que;
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> board[j][k][i];
				if (board[j][k][i] == 1) {
					que.push({ j,k,i });
					vis[j][k][i] = 1;
				}
			}
		}
	}

	int x, y, z;
	while (!que.empty())
	{
		tie(x, y, z) = que.front();
		que.pop();
		//P(n, m, h);
		for (int dir = 0; dir < 6; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			int nz = z + dz[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) {
				continue;
			}
			if (vis[nx][ny][nz] || board[nx][ny][nz] == -1) {
				continue;
			}
			vis[nx][ny][nz] = 1;
			dis[nx][ny][nz] = dis[x][y][z] + 1;
			que.push({ nx,ny,nz });
		}
	}

	int ans = -1;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (board[j][k][i] == 0 && dis[j][k][i] == 0) {
					cout << -1;
					exit(0);
				}
				if (ans < dis[j][k][i]) {
					ans = dis[j][k][i];
				}
			}
		}
	}
	cout << ans;




	return 0;
}