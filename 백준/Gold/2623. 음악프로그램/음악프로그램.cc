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

int	deg[1001];
vector<int> arr[1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	int t;
	int a;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		vector<int> temp;
		cin >> t;
		while (t--)
		{
			cin >> a;
			temp.push_back(a);
		}
		for (int j = 0; j < temp.size() - 1; j++) {
			for (int k = j + 1; k < temp.size(); k++) {
				arr[temp[j]].push_back(temp[k]);
				deg[temp[k]]++;
			}
		}
	}

	queue<int> que;
	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) {
			que.push(i);
		}
	}
	while (!que.empty())
	{
		int cur = que.front();
		ans.push_back(cur);
		que.pop();
		for (int i = 0; i < arr[cur].size(); i++) {
			deg[arr[cur][i]]--;
			if (deg[arr[cur][i]] == 0) {
				que.push(arr[cur][i]);
			}
		}
	}
	if (ans.size() != n) {
		cout << 0;
	}
	else {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << endl;
		}
	}
	


	return 0;
}