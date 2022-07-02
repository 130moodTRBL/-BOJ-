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

int board[129][129];
int blue = 0;
int white = 0;

void sol(int x, int y, int n)
{
	int i, j;
	int cntB = 0;
	int cntW = 0;
	for (i = x; i < x + n; i++) {
		for (j = y; j < y + n; j++) {
			if (board[i][j] == 1) {
				cntB++;
			}
			if (board[i][j] == 0) {
				cntW++;
			}
		}
	}

	if (cntB == n * n) {
		blue++;
		return;
	}
	else if (cntW == n * n) {
		white++;	
		return;
	}
	else {
		if (n == 1) {
			return;
		}
		sol(x, y, n / 2);
		sol(x, y + (n / 2), n / 2);
		sol(x + (n / 2), y, n / 2);
		sol(x + (n / 2), y + (n / 2), n / 2);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
		}
	}
	sol(1, 1, n);
	cout << white << endl << blue;



	return 0;
}