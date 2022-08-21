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

int board[101][101];
int vis[101][101];
int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	int r, c, d;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	int cnt = 1;
	int check = 0;
	vis[r][c] = 1;
	while (1)
	{
		d = (d + 3) % 4;
		int tempC = c + dx[d];
		int tempR = r + dy[d];
		if (board[tempR][tempC] == 0 && vis[tempR][tempC] == 0) {
			r = tempR;
			c = tempC;
			vis[tempR][tempC] = 1;
			cnt++;
			check = 0;
		}
		else {
			check++;
		}

		if (check == 4) {
			int nc = c + dx[(d + 2) % 4];
			int nr = r + dy[(d + 2) % 4];
			if (board[nr][nc] == 0) {
				vis[nr][nc] = 1;
				//cnt++;
				check = 0;
				c = nc;
				r = nr;
			}
			else {
				cout << cnt;
				exit(0);
			}
		}
	}




	return 0;
}