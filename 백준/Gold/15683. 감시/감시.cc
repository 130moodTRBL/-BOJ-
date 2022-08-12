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

int board[9][9];
int temp[9][9];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<pair<int, int>> arr;
int n, m;

void fill()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			temp[i][j] = board[i][j];
		}
	}
}

void sol(int x, int y, int dir)
{
	dir %= 4;
	while (1)
	{
		x = x + dx[dir];
		y = y + dy[dir];
		//cout << x << " " << y << endl;
		if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] == 6) {
			break;
		}
		if (board[x][y] != 0) {
			continue;
		}
		temp[x][y] = 9;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] != 0 && board[i][j] != 6) {
				arr.push_back({ i,j });
			}
		}
	}
	
	int x, y, dir, c;
	int ans = 999999999;
	int cnt = 0;
	for (int cir = 0; cir < (1 << (2 * arr.size())); cir++) {
		fill();
		c = cir;
		for (int i = 0; i < arr.size(); i++) {
			dir = c % 4;
			//cout << dir << endl;
			c /= 4;
			tie(x, y) = arr[i];
			if (board[x][y] == 1) {
				sol(x, y, dir);
			}
			else if (board[x][y] == 2) {
				sol(x, y, dir);
				sol(x, y, dir + 2);
			}
			else if (board[x][y] == 3) {
				sol(x, y, dir);
				sol(x, y, dir + 1);
			}
			else if (board[x][y] == 4) {
				sol(x, y, dir);
				sol(x, y, dir + 1);
				sol(x, y, dir + 2);
			}
			else if (board[x][y] == 5) {
				sol(x, y, dir);
				sol(x, y, dir + 1);
				sol(x, y, dir + 2);
				sol(x, y, dir + 3);
			}
		}
		cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (temp[i][j] == 0) {
					cnt++;
				}
			}
		}
		ans = min(ans, cnt);
	}
	cout << ans;



	return 0;
}