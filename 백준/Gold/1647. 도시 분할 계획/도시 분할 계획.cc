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

vector<pair<int, int>> arr[1000001];
vector<int> ans;
priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<tuple<int, int>>> que;
int vis[1000001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	int a, b, c;
	int temp = -1;
	long long sum = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		arr[a].push_back({ c,b });
		arr[b].push_back({ c,a });
	}

	vis[1] = 1;
	for (int i = 0; i < arr[1].size(); i++) {
		que.push({ arr[1][i].first,arr[1][i].second });
	}

	int dis, x;
	while (!que.empty())
	{
		tie(dis, x) = que.top();
		que.pop();
		if (vis[x]) {
			continue;
		}
		vis[x] = 1;
		sum += dis;
		temp = max(temp, dis);
		for (int i = 0; i < arr[x].size(); i++) {
			que.push({ arr[x][i].first,arr[x][i].second });
		}
	}
	cout << sum - temp;



	return 0;
}