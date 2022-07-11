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

vector<pair<int, int>> arr[10011];
int vis[10011];
int sum = -1;
int flag;
int n;

void sol(int root, int x)
{
	vis[root] = 1;
	
	if (sum < x) {
		sum = x;
		flag = root;
	}

	for (int i = 0; i < arr[root].size(); i++) {
		int next = arr[root][i].first;
		int cur = arr[root][i].second + x;
		//printf("dis: %d\n", arr[root][i].second);
		if (vis[next] != 1) {
			vis[next] = 1;
			sol(next, cur);
			vis[next] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b, dis;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> dis;
		arr[a].push_back({ b,dis });
		arr[b].push_back({ a,dis });
	}
	sol(1, 0);
	memset(vis, 0, sizeof(vis));
	sum = 0;
	sol(flag, 0);
	cout << sum;
	

	return 0;
}