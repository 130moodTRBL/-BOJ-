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

int arr[1001][1001];
bool vis[1001] = { 0 };

void sol(int num, int n)
{
	vis[num] = 1;
	for (int i = 1; i <= n; i++) {
		if (arr[num][i] && !vis[i]) {
			sol(i, n);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	int a, b;
	int i, j;
	int cnt = 0;
	cin >> n >> m;

	for (i = 0; i < m; i++) {
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	for (i = 1; i <= n; i++) {
		if (!vis[i]) {
			cnt++;
			sol(i, n);
		}
	}
	cout << cnt;
	

	return 0;
}