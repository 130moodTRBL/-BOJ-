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

int arr[100001];
int dp1[100001];
int dp2[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	int ans = -1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		dp1[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp1[i] = max(dp1[i], dp1[j] + 1);
			}
		}
	}

	for (int i = n; i >= 1; i--) {
		dp2[i] = 1;
		for (int j = n; j > i; j--) {
			if (arr[i] > arr[j]) {
				dp2[i] = max(dp2[i], dp2[j] + 1);
			}
		}
	}

	int tempa, tempb;
	tempa = tempb = -1;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp1[i] + dp2[i] - 1);
	}

	cout << ans;



	return 0;
}