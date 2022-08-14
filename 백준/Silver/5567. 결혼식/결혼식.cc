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
int vis[501];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	int a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	int cnt = 0;
	for (int i = 0; i < edge[1].size(); i++) {
		vis[edge[1][i]] = 1;
		for (int j = 0; j < edge[edge[1][i]].size(); j++) {	
			vis[edge[edge[1][i]][j]] = 1;
		}
	}
	for (int i = 2; i < 501; i++) {
		if (vis[i] != 0) {
			cnt++;
		}
	}
	cout << cnt;



	return 0;
}