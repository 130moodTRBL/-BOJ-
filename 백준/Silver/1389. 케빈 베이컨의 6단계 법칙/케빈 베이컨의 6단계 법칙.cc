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

vector<int> edge[501];
int cnt[501];
int vis[501];
int sum[501];
vector<pair<int, int>> arr;
int n, m;

void sol(int num)
{
	queue<int> que;
	que.push(num);
	while (!que.empty())
	{
		int cur = que.front();
		que.pop();
		for (auto next : edge[cur]) {
			if (vis[next]) {
				continue;
			}
			vis[next] = 1;
			que.push(next);
			cnt[next] = cnt[cur] + 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		sum[num] += cnt[i];
	}
}

void fill()
{
	for (int i = 0; i <= n; i++) {
		vis[i] = 0;
		cnt[i] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		fill();
		sol(i);
	}
	int ans = 999999999;
	int temp;
	for (int i = 1; i <= n; i++) {
		if (ans > sum[i]) {
			ans = sum[i];
			temp = i;
		}
	}
	cout << temp;
	



	return 0;
}