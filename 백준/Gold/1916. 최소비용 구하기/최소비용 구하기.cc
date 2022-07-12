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

vector<pair<int, int>> arr[100001];
int dis[100001];
int start, last;
int inf = 1999999999;

void sol(int root)
{
	dis[root] = 0;
	queue<pair<int, int>> que;
	//priority_queue<pair<int, int>> que;
	que.push({ dis[root],root });

	while (!que.empty())
	{
		int cur = que.front().second;
		int d = que.front().first;
		que.pop();
		if (dis[cur] < d) {
			continue;
		}
		for (int i = 0; i < arr[cur].size(); i++) {
			int next = arr[cur][i].first;
			int nextD = d + arr[cur][i].second;
			if (nextD < dis[next]) {
				//printf("next: %d, dis: %d\n", next, nextD);
				dis[next] = nextD;
				que.push({ nextD,next });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	int a, b, d;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> d;
		arr[a].push_back({ b,d });
	}
	cin >> start >> last;

	for (int i = 1; i <= n; i++) {
		dis[i] = inf;
	}

	sol(start);
	cout << dis[last];

	

	return 0;
}