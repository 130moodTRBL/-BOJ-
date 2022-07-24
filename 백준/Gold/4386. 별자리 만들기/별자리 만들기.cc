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

vector<pair<float, float>> point;
vector<tuple<float, float, float>> edge;
int parent[1001];

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

	int n;
	int i, j;
	float a, b;
	float sum = 0;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a >> b;
		point.push_back({ a,b });
	}

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	float x1, x2, y1, y2;
	float dis;
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			tie(x1, y1) = point[i];
			tie(x2, y2) = point[j];
			dis = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
			edge.push_back({ dis,i,j });
		}
	}
	sort(edge.begin(), edge.end());

	int x, y;
	for (int i = 0; i < edge.size(); i++) {
		tie(dis, x, y) = edge[i];
		if (!find(x, y)) {
			sum += dis;
			unionParent(x, y);
		}
	}
	cout << sum;
	



	return 0;
}