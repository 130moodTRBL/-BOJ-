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

vector<pair<int, int>> arr;
vector<int> bag;
priority_queue<int> que;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k, m, v, c;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> m >> v;
		arr.push_back({ m,v });
	}
	for (int i = 0; i < k; i++) {
		cin >> c;
		bag.push_back(c);
	}

	sort(arr.begin(), arr.end());
	sort(bag.begin(), bag.end());

	int pos = 0;
	long long sum = 0;
	for (int i = 0; i < k; i++) {
		while (pos < n && arr[pos].first <= bag[i])
		{
			//cout<<"hi: "<<bag[i];
			que.push(arr[pos].second);
			pos++;
		}

		if (!que.empty()) {
			sum += que.top();
			que.pop();
		}
		//cout << "afsdasfasdf" << endl;
	}
	cout << sum;


	return 0;
}