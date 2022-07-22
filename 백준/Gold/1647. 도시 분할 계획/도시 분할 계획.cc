#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool check[100001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int,int>>>v(n + 1);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		v[x].push_back(make_pair(y, z));
		v[y].push_back(make_pair(x, z));
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
	q.push(make_pair(0,1));
	int maxcost = -1;
	int ans = 0;
	while (!q.empty()) {
		int fd = q.top().first;
		int fx = q.top().second;
		q.pop();
		if (check[fx])	continue;
		check[fx] = true;
		if (maxcost < fd)	maxcost = fd;
		ans += fd;
		for (int k = 0; k < v[fx].size(); k++) {
			int nx = v[fx][k].first;
			int cost = v[fx][k].second;
			q.push(make_pair(cost, nx));			
		}
	}
	ans -= maxcost;
	cout << ans << '\n';
	return 0;
}