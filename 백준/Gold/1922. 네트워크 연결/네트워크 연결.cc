#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <tuple>

#define endl '\n'
using namespace std;

vector<tuple<int, int, int>> edge;
int parent[100001];

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

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	int a, b, c;
	int sum = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (a != b) {
			edge.push_back({ c,a,b });
		}
	}
	sort(edge.begin(), edge.end());
	for (int i = 0; i < 1001; i++) {
		parent[i] = i;
	}

	int x, y, dis;
	for (int i = 0; i < edge.size(); i++) {
		tie(dis, x, y) = edge[i];
		if (find(x, y) == 0) {
			sum += dis;
			unionParent(x, y);
		}
	}
	cout << sum;


	return 0;
}