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

int parent[1000001];

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
	if (a > b) {
		parent[a] = b;
	}
	else {
		parent[b] = a;
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
	int a, b;
	int ans = 0;
	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		if (find(a, b)) {
			ans = i;
			break;
		}
		unionParent(a, b);
	}

	cout << ans;



	return 0;
}