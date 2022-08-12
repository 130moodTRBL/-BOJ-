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

int parent[10001];
int cost[10001];
vector<int> arr;

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
	if (cost[a] < cost[b]) {
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

	int n, m, k;
	int a, b;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}

	for (int i = 0; i < 10001; i++) {
		parent[i] = i;
	}

	while (m--)
	{
		cin >> a >> b;
		unionParent(a, b);
	}
	for (int i = 1; i <= n; i++) {
		arr.push_back(getParent(i));
	}
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	int sum = 0;
	for (int i = 0; i < arr.size(); i++) {
		sum += cost[arr[i]];
	}
	if (sum <= k) {
		cout << sum;
	}
	else {
		cout << "Oh no";
	}



	return 0;
}