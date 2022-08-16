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

int vis[1000001];
int dis[1000001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;
	if (s == g) {
		cout << 0;
		exit(0);
	}

	queue<int> que;
	que.push(s);
	vis[s] = 1;
	while (!que.empty())
	{
		int cur = que.front();
		que.pop();
		vis[cur] = 1;
		int na = cur + u;
		int nb = cur - d;
		if (cur == g) {
			cout << dis[cur];
			exit(0);
		}

		if (na <= f && vis[na] != 1) {
			que.push(na);
			vis[na] = 1;
			dis[na] = dis[cur] + 1;
			//cout << "hi";
		}
		if (nb > 0 && vis[nb] != 1) {
			que.push(nb);
			vis[nb] = 1;
			dis[nb] = dis[cur] + 1;
			//cout << "hi";
		}
	}
	cout << "use the stairs";



	return 0;
}