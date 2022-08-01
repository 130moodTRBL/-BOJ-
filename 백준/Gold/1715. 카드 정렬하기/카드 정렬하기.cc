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

priority_queue<int, vector<int>, greater<int>> arr;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	int x;
	int sum = 0;
	int ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		arr.push(x);
	}

	int a, b;
	while (arr.size() != 1)
	{
		a = arr.top();
		arr.pop();
		/*if (arr.empty()) {
			cout << ans;
			exit(0);
		}*/

		b = arr.top();
		arr.pop();
		/*if (arr.empty()) {
			cout << ans;
			exit(0);
		}*/

		sum = a + b;
		ans += sum;
		arr.push(sum);
	}
	cout << ans;



	return 0;
}