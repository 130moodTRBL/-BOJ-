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

vector<pair<int, int>> edge[101];
int dis[101];
int tem[101];
const int INF = 999999999;

void fill()
{
	for (int i = 0; i < 101; i++) {
		dis[i] = INF;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, r;
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		cin >> tem[i];
	}

	int a, b, d;
	for (int i = 0; i < r; i++) {
		cin >> a >> b >> d;
		edge[a].push_back({ b,d });
		edge[b].push_back({ a,d });
	}
	
	int ans = -1;
	for (int i = 1; i <= n; i++) {
		fill();
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
		que.push({ 0,i });
		dis[i] = 0;

		int cur, curD;
		while (!que.empty())
		{
			tie(curD, cur) = que.top();
			que.pop();
			for (int j = 0; j < edge[cur].size(); j++) {
				int next = edge[cur][j].first;
				int nextD = edge[cur][j].second;
				if (curD + nextD < dis[next]) {
					dis[next] = nextD + curD;
					que.push({ nextD + curD,next });
				}
			}
		}

		int temp = 0;
		for (int k = 1; k <= n; k++) {
			if (m >= dis[k]) {
				temp += tem[k];
			}
		}
		ans = max(ans, temp);
	}
	cout << ans;



	return 0;
}