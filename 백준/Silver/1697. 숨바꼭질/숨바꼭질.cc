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

using namespace std;

queue<pair<int, int>> que;
bool vis[100001];

bool check(int n) {
	if (n < 0 || n > 100000 || vis[n])
		return 0;
	return 1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	int cnt;
	int temp;
	int ans = 0;
	cin >> n >> k;
	que.push({ n,0 });
	vis[n] = 1;
	while (!que.empty())
	{
		int temp = que.front().first;
		int cnt = que.front().second;
		que.pop();
		if (k == temp) {
			ans = cnt;
			break;
		}
		if (check(temp - 1)) {
			que.push({ temp - 1,cnt + 1 });
			vis[temp - 1] = 1;
		}
		if (check(temp + 1)) {
			que.push({ temp + 1,cnt + 1 });
			vis[temp + 1] = 1;
		}
		if (check(2 * temp)) {
			que.push({ 2 * temp,cnt + 1 });
			vis[2 * temp] = 1;
		}

	}
	cout << ans;

	

	return 0;
}