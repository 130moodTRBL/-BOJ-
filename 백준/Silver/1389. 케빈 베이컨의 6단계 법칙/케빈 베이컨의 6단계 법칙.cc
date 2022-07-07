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

#define endl '\n'

using namespace std;

int adj[5011][5011];
int vis[5011];
int cnt[5011];
int sum[5011];

int n, m;

void bfs(int root)
{
	queue<int> que;
	que.push(root);
	while (!que.empty())
	{
		int cur = que.front();
		que.pop();
		for (int i = 1; i <= n; i++) {
			if (adj[cur][i] == 1 && vis[i] != 1) {
				vis[i] = 1;
				que.push(i);
				cnt[i] = cnt[cur] + 1;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		sum[root] += cnt[i];
	}
	sum[root] -= cnt[root];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b;
	int temp = 0;
	int min = 99999;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[a][b] = 1;
		adj[b][a] = 1;
	}

	for (int i = 1; i <= n; i++) {
		bfs(i);
		memset(vis, 0, sizeof(vis));
		memset(cnt, 0, sizeof(cnt));
	}
	for (int i = 1; i <= n; i++) {
		if (sum[i] < min) {
			min = sum[i];
			temp = i;
		}
	}
	cout << temp;
	

	return 0;
}