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

int vis[100001];

int check(int n)
{
	if (n < 0 || n > 10000 || vis[n]) {
		return 0;
	}
	return 1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	int ans = 0;
	cin >> n >> k;
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
	que.push({ 0,n });
	vis[n] = 1;
	while (!que.empty())
	{
		int temp = que.top().second;
		int cnt = que.top().first;
		que.pop();
		if (k == temp) {
			ans = cnt;
			break;
		}

		if (temp * 2 < 100001 && vis[temp * 2] != 1) {
			que.push({ cnt,temp * 2 });
			vis[temp * 2] = 1;
		}
		if (temp + 1 < 100001 && vis[temp + 1] != 1) {
			que.push({ cnt + 1,temp + 1 });
			vis[temp + 1] = 1;
		}
		if (temp - 1 >= 0 && vis[temp - 1] != 1) {
			que.push({ cnt + 1,temp - 1 });
			vis[temp - 1] = 1;
		}
	}
	cout << ans;




	return 0;
}