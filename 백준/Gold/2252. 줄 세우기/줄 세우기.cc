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

int indegree[32001];
vector<int> arr[32001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	int a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		arr[a].push_back(b);
		indegree[b]++;
	}
	
	queue<int> que;
	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			que.push(i);
		}
	}
	while (!que.empty())
	{
		int cur = que.front();
		ans.push_back(cur);
		que.pop();
		for (int i = 0; i < arr[cur].size(); i++) {
			indegree[arr[cur][i]]--;
			if (indegree[arr[cur][i]] == 0) {
				que.push(arr[cur][i]);
			}
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}




	return 0;
}