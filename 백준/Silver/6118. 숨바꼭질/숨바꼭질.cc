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

vector<int> edge[20001];
int vis[20001];
int dis[20001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	queue<int> que;
	que.push(1);
	vis[1] = 1;
	while (!que.empty())
	{
		int cur = que.front();
		que.pop();
		for (auto next : edge[cur]) {
			if (vis[next]) {
				continue;
			}
			que.push(next);
			vis[next] = 1;
			dis[next] = dis[cur] + 1;
		}
	}

	int temp = -1;
	int x;
	for (int i = 1; i <= n; i++) {
		if (temp < dis[i]) {
			temp = dis[i];
			x = i;
		}
	}

	vector<int> arr;
	for (int i = 1; i <= n; i++) {
		//cout << dis[i] << endl;
		if (dis[x] == dis[i]) {
			arr.push_back(i);
		}
	}
	cout << x << " " << dis[x] << " " << arr.size();




	return 0;
}