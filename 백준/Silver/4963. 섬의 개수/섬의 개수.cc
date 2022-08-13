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

int board[100][100];
int vis[100][100];
int dx[] = { 0,1,0,-1,1,1,-1,-1 };
int dy[] = { 1,0,-1,0,1,-1,1,-1 };

void fill()
{
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			vis[i][j] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (1)
	{
		int n, m;
		int cnt = 0;
		fill();
		cin >> m >> n;
		if (n == 0 && m == 0) {
			break;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> board[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 0 || vis[i][j]) {
					continue;
				}
				queue<pair<int, int>> que;
				que.push({ i,j });
				vis[i][j] = 1;
				cnt++;
				while (!que.empty())
				{
					pair<int, int> cur = que.front();
					que.pop();
					//cout << cur.first << " " << cur.second << endl;
					for (int dir = 0; dir < 8; dir++) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
							continue;
						}
						if (board[nx][ny] == 0 || vis[nx][ny]) {
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