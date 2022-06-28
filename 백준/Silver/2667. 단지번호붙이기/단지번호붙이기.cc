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

using namespace std;

#define X first
#define Y second

char board[502][502];
bool vis[502][502];
vector<int> house;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int i, j;
	int cnt = 0;
	int h = 0;
	cin >> n;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
		

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (board[i][j] =='0' || vis[i][j]) {
				continue;
			}
			queue<pair<int, int>> que;
			que.push({ i,j });
			vis[i][j] = 1;
			cnt++;
			h = 1;
			while (!que.empty())
			{
				pair<int, int> cur = que.front();
				que.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
						continue;
					}
					if (vis[nx][ny] || board[nx][ny] != '1') {
						continue;
					}
					vis[nx][ny] = 1;
					h++;
					que.push({ nx,ny });
				}
			}
			house.push_back(h);
		}
	}
	sort(house.begin(), house.end());
	cout << cnt << endl;
	for (i = 0; i < cnt; i++) {
		cout << house[i] << endl;
	}
	

	


	return 0;
}