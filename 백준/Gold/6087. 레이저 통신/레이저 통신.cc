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

char board[101][101];
int vis[101][101];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int n, m;
vector<pair<int, int>> edge;
int ans = 1999999999;

void fill()
{
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			vis[i][j] = 1999999999;
		}
	}
}

int sol(int a, int b)
{
	queue <tuple<int, int, int, int>> que;
	for (int i = 0; i < 4; i++) {
		que.push({ a,b,i,0 });
	}

	int lx, ly;
	tie(lx, ly) = edge[1];
	int x, y, z, cnt;
	while (!que.empty())
	{
		tie(x, y, z, cnt) = que.front();
		que.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			int temp = cnt;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				continue;
			}
			if (board[nx][ny] == '*') {
				continue;
			}

			if (dir != z) {
				temp++;
			}
			if (vis[nx][ny] >= temp) {
				vis[nx][ny] = temp;
				que.push({ nx,ny,dir,temp });
				//cout << nx << " " << ny << " " << temp << endl;
			}
		}
	}

	return vis[lx][ly];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'C') {
				edge.push_back({ i,j });
				//cout << i << " " << j << endl;
			}
		}
	}
	fill();

	int x, y;
	tie(x, y) = edge[0];
	cout << sol(x, y);




	return 0;
}