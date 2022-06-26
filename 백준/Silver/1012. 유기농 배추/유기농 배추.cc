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

int board[502][502] = { 0 };
bool vis[502][502];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	int i, j;
	int a, b;
	int t;
	int cnt = 0;
	queue<pair<int, int>> que;

	cin >> t;
	while (t--)
	{
		cnt = 0;
		for (i = 0; i < 502; i++) {
			for (j = 0; j < 502; j++) {
				board[i][j] = 0;
				vis[i][j] = 0;
			}
		}
		cin >> m >> n >> k;
		for (i = 0; i < k; i++) {
			cin >> a >> b;
			board[b][a] = 1;
		}

		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				if (board[i][j] == 0 || vis[i][j]) {
					continue;
				}
				
				vis[i][j] = 1;
				que.push({ i,j });
				cnt++;
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
						vis[nx][ny] = 1;
						que.push({ nx,ny });
					}
				}
			}
		}
		cout << cnt << endl;
	}
	

	


	return 0;
}