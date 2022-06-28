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

using namespace std;

int arr[1001];
int dp[1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int i, j;
	int max = -1;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (i = 0; i < n; i++) {
		dp[i] = 1;
		for (j = i - 1; j >= 0; j--) {
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				continue;
			}
		}
	}
	for (i = 0; i < n; i++) {
		if (max < dp[i])
			max = dp[i];
	}
	cout << max;




	return 0;
}