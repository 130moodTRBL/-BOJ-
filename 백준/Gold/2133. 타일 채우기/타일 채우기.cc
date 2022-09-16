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

#define endl '\n'
using namespace std;

int dp[31];
int arr[31];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	dp[0] = 1;
	dp[2] = 3;
	dp[4] = 11;
	
	for (int i = 4; i <= n; i += 2) {
		dp[i] = dp[i - 2] * dp[2];
		for (int j = i - 4; j >= 0; j -= 2) {
			dp[i] += dp[j] * 2;
		}
	}
	cout << dp[n];
	
	



	return 0;
}