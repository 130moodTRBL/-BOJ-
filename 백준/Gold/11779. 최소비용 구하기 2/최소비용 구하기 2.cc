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
#include <tuple>

#define endl '\n'

using namespace std;

vector<pair<int, int>> arr[100001];
vector<int> len;
int dis[100001];
int vis[100001];
const int INF = 99999999;

void fill()
{
	for (int i = 0; i < 100001; i++) {
		dis[i] = INF;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	int a, b, c;
	int start, last;
	int tempA = -1;
	int tempB = -1;
	int tempC = -1;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (tempA == a && tempB == b && tempC > c) {
			arr[a].pop_back();
		}
		arr[a].push_back({ b,c });
		tempA = a;
		tempB = b;
		tempC = c;
	}
	cin >> start >> last;
	fill();
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
	dis[start] = 0;
	que.push({ 0,start });
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
				vis[next] = cur;
				que.push({ dis[next],next });
			}
		}
	}
	cout << dis[last] << endl;
	int temp = last;
	while (temp)
	{
		len.push_back(temp);
		temp = vis[temp];
	}
	cout << len.size() << endl;
	for (int i = len.size() - 1; i >= 0 ; i--) {
		cout << len[i] << " ";
	}



	return 0;
}