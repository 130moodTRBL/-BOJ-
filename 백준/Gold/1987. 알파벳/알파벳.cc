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
#include <set>

#define endl '\n'
using namespace std;

int r, c;
char board[21][21];
int vis[21][21];
int flag[301];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int temp = -1;

void sol(int x, int y, int num)
{
	flag[board[x][y] - 'A'] = 1;
	temp = max(temp, num);

	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
			continue;
		}

		char word = board[nx][ny];
		if (flag[word - 'A'] == 0) {
			flag[word - 'A'] = 1;
			sol(nx, ny, num + 1);
			flag[word - 'A'] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
		}
	}
	sol(0, 0, 1);
	cout << temp;



	return 0;
}