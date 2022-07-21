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

int board[101][101];
int dis[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int shark = 2;

void fill()
{
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			dis[i][j] = -1;
		}
	}
		
	
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	int i, j;
	int x, y;
	int feed = 0;
	int time = 0;
	queue<pair<int, int>> que;
	cin >> n;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 9) {
				x = i;
				y = j;
			}
		}
	}

	while (1)
	{
		vector<pair<int, int>> fish;
		fill();
		board[x][y] = 0;
		dis[x][y] = 0;
		que.push({ x,y });
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
				if (dis[nx][ny] != -1) {
					continue;
				}
				if (board[nx][ny] > shark) {
					continue;
				}
				else if (board[nx][ny] == shark || board[nx][ny] == 0) {
					dis[nx][ny] = dis[cur.X][cur.Y] + 1;
					que.push({ nx,ny });
				}
				else if (board[nx][ny] < shark || board[nx][ny] >= 1) {
					dis[nx][ny] = dis[cur.X][cur.Y] + 1;
					que.push({ nx,ny });
					fish.push_back({ nx,ny });
				}
			}
		}

		if (fish.size() == 0) {
			break;
		}
		else if (fish.size() == 1) {
			x = fish[0].X;
			y = fish[0].Y;
			board[x][y] = 0;
			feed++;
			time += dis[x][y];
		}
		else {
			int d = 999999;
			for (int i = 0; i < fish.size(); i++) {
				d = min(d, dis[fish[i].first][fish[i].second]);
			}
			vector<pair<int, int>> yee;
			for (int i = 0; i < fish.size(); i++) {
				if (d == dis[fish[i].first][fish[i].second]) {
					yee.push_back({ fish[i].first,fish[i].second });
				}
			}
			if (yee.size() == 1) {
				x = yee[0].X;
				y = yee[0].Y;
				board[x][y] = 0;
				feed++;
				time += dis[x][y];
			}
			else {
				sort(yee.begin(), yee.end());
				x = yee[0].X;
				y = yee[0].Y;
				board[x][y] = 0;
				feed++;
				time += dis[x][y];
			}
		}
		
		if (feed >= shark) {
			feed -= shark;
			shark++;
		}
	}
	cout << time;




	return 0;
}