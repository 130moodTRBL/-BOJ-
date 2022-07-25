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

vector<tuple<int, int, int>> edge;
int parent[10001];
char school[10001];

int getParent(int x)
{
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	if (a < b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}

int find(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	if (a == b) {
		return 1;
	}
	return 0;
}

void fill()
{
	for (int i = 0; i < 10001; i++) {
		parent[i] = i;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	int a, b, c;
	int sum = 0;
	int cnt = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> school[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (school[a] != school[b]) {
			edge.push_back({ c,a,b });
		}
	}
	sort(edge.begin(), edge.end());
	fill();

	int dis, x, y;
	for (int i = 0; i < edge.size(); i++) {
		tie(dis, x, y) = edge[i];
		if (!find(x, y)) {
			sum += dis;
			unionParent(x, y);
			cnt++;
		}
	}
	if (cnt != n - 1 ) {
		cout << -1;
	}
	else {
		cout << sum;
	}
	




	return 0;
}