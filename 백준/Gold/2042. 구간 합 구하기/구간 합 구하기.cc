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
#include <set>
#include <deque>

#define endl '\n'
using namespace std;

long long tree[1000001 * 4];
long long arr[1000001];

#define int long long

int init(int start, int end, int node)
{
	if (start == end) {
		return tree[node] = arr[start];
	}
	int mid = (start + end) / 2;

	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

int sum(int start, int end, int left, int right, int node)
{
	if (left > end || right < start) {
		return 0;
	}

	if (left <= start && end <= right) {
		return tree[node];
	}

	int mid = (start + end) / 2;
	return sum(start, mid, left, right, node * 2) + sum(mid + 1, end, left, right, node * 2 + 1);
}

void update(int start, int end, int idx, long long diff, int node)
{
	if (idx < start || idx > end) {
		return;
	}
	tree[node] = tree[node] + diff;

	if (start != end) {
		int mid = (start + end) / 2;
		update(start, mid, idx, diff, node * 2);
		update(mid + 1, end, idx, diff, node * 2 + 1);
	}
}

#undef int

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	init(1, n, 1);

	long long a, b, c;
	for (int i = 0; i < m + k; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			long long diff = c - arr[b];
			arr[b] = c;
			update(1, n, b, diff, 1);
		}
		else if (a == 2) {
			cout << sum(1, n, b, c, 1) << endl;
		}
	}




	return 0;
}