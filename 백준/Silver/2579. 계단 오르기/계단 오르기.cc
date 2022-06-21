#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

int main() 
{
	int n;
	int i;
	int arr[301] = { 0 };
	int dp[301] = { 0 };
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dp[0] = arr[0];
	dp[1] = max(dp[0] + arr[1], arr[1]);
	dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]);
	for (i = 3; i < n; i++) {
		dp[i] = max(arr[i] + dp[i - 2], arr[i] + arr[i - 1] + dp[i - 3]);
	}
	cout << dp[n - 1];
	


	return 0;
}