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

vector<int> edge[101];
int vis[101];
int n, m;
int start, last;

void sol(int num, int level)
{
	if (num == last) {
		cout << level;
		exit(0);
	}
	vis[num] = 1;
	for (auto next : edge[num]) {
		if (vis[next]) {
			continue;
		}
		sol(next, level + 1);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	cin >> start >> last;
	cin >> m;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	sol(start, 0);
	cout << -1;



	return 0;
}