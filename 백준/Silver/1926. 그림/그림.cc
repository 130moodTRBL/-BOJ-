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

int board[502][502];
bool vis[502][502];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	int i, j;
	int cnt = 0;
	int paint = 1;
	int maxP = 0;

	cin >> n >> m;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (board[i][j] == 0 || vis[i][j]) {
				continue;
			}
			queue<pair<int, int>> que;
			cnt++;
			vis[i][j] = 1;
			que.push({ i,j });
			paint = 1;
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
					if (vis[nx][ny] || board[nx][ny] != 1) {
						continue;
					}
					paint++;
					vis[nx][ny] = 1;
					que.push({ nx,ny });
				}
			}
			maxP = max(maxP, paint);
		}
	}
	cout << cnt << endl << maxP;
	

	return 0;
}