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
int dp[1500001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);	
	cout.tie(0);

	long long n;
	cin >> n;
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i < 1500000; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000;
	}
	cout << dp[n % 1500000];
	
	

	//1500000

	return 0;
}