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

vector<pair<int, int>> arr[10001];
int dis[10001];
const int INF = 19999999;

void fill()
{
	for (int i = 0; i < 10001; i++) {
		dis[i] = INF;
	}
}

void dijk(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
	dis[start] = 0;
	que.push({ dis[start],start });
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

	int n, m, x;
	int a, b, c;
	int temp = -1;
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		arr[a].push_back({ b,c });
	}

	for (int i = 1; i <= n; i++) {
		fill();
		dijk(i);
		int first = dis[x];

		fill();
		dijk(x);
		int second = dis[i];
		temp = max(temp, first + second);
	}
	cout << temp;


	return 0;
}