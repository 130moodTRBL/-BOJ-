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

vector<int> arr[100001];
vector<int> ans;
vector<int> temp;
int deg[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	int a, b;
	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b;
		arr[a].push_back(b);
		deg[b]++;
	}
	priority_queue<int, vector<int>, greater<int>> que;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) {
			que.push(i);
		}
	}

	while (!que.empty())
	{
		int cur = que.top();
		ans.push_back(cur);	
		que.pop();
		for (int i = 0; i < arr[cur].size(); i++) {
			deg[arr[cur][i]]--;
			if (deg[arr[cur][i]] == 0) {
				que.push(arr[cur][i]);
			}
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}



	return 0;
}