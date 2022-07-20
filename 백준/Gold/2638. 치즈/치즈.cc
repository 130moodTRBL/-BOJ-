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

#define endl '\n'

using namespace std;

#define X first
#define Y second
int board[502][502];
int vis[502][502];
int temp[502][502];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int check()
{
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (board[i][j] == 1) {
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	queue<pair<int, int>> que;
	int n, m;
	int i, j;
	int time = 0;
	int cnt = 0;
	cin >> n >> m;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	while (1)
	{
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				temp[i][j] = board[i][j];
				vis[i][j] = 0;
			}
		}

		que.push({ 0,0 });
		vis[0][0] = 1;
		while (!que.empty()) 
		{
			pair<int, int> cur = que.front();
			int x = cur.X;
			int y = cur.Y;
			que.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
					continue;
				}
				if (vis[nx][ny] == 1) {
					continue;
				}
				if (board[nx][ny]) {
					board[nx][ny]++;
				}
				else if (board[nx][ny] == 0) {
					que.push({ nx,ny });
					vis[nx][ny] = 1;
				}
			}
		}
		
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				if (board[i][j] > 2) {
					temp[i][j] = 0;
				}
				board[i][j] = temp[i][j];
			}
		}
		time++;
		if (check() == 0) {
			break;
		}
	}
	cout << time;

	
	/*7 7

		0 0 0 0 0 0 0
		0 1 1 1 1 1 0
		0 1 0 0 0 1 0
		0 1 0 1 0 1 0
		0 1 0 0 0 1 0
		0 1 1 1 1 1 0
		0 0 0 0 0 0 0*/



	return 0;
}