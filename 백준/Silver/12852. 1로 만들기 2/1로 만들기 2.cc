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

int dp[10000001];
int vis[10000001];

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	dp[1] = 0;
	vis[1] = 0;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		vis[i] = i - 1;
		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
			dp[i] = dp[i / 3] + 1;
			vis[i] = i / 3;
		}
		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
			dp[i] = dp[i / 2] + 1;
			vis[i] = i / 2;
		}
	}
	cout << dp[n] << endl;

	int temp = n;
	
	while (temp != 0)
	{
		cout << temp << " ";
		temp = vis[temp];
	}




	return 0;
}