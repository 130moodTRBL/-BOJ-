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

vector<pair<int, int>> arr[200001];
int dis[200001];
const int INF = 9999999;

void dijk(int root)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
	dis[root] = 0;
	que.push({ dis[root],root });
	while (!que.empty())
	{
		int cur = que.top().second;
		int d = que.top().first;
		que.pop();
		for (int i = 0; i < arr[cur].size(); i++) {
			int next = arr[cur][i].first;
			int nextD = arr[cur][i].second;
			if (nextD + d < dis[next]) {
				dis[next] = nextD + d;
				que.push({ dis[next],next });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, e;
	int a, b, c;
	int v1, v2;
	int start, mid, last;

	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		arr[a].push_back({ b,c });
		arr[b].push_back({ a,c });
	}
	cin >> v1 >> v2;

	//
	memset(dis, INF, sizeof(dis));
	dijk(1);
	start = dis[v1];

	memset(dis, INF, sizeof(dis));
	dijk(v1);
	mid = dis[v2];
	
	memset(dis, INF, sizeof(dis));
	dijk(v2);
	last = dis[n];
	int test1 = start + mid + last;
	
	//
	memset(dis, INF, sizeof(dis));
	dijk(1);
	start = dis[v2];

	memset(dis, INF, sizeof(dis));
	dijk(v2);
	mid = dis[v1];

	memset(dis, INF, sizeof(dis));
	dijk(v1);
	last = dis[n];
	int test2 = start + mid + last;

	if (min(test1, test2) >= INF) {
		cout << -1;
	}
	else {
		cout << min(test1, test2);
	}
	


	return 0;
}