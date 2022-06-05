#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <stdlib.h>
#include <string.h>

using namespace std;

int arr[100001];
int dp[100001];
int main()
{
	int n;
	int val;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	dp[0] = arr[0];
	val = arr[0];

	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);		//10 -4 3 1 5 6 -35 12 21 -1
		val = max(val, dp[i]);
	}
	printf("%d\n", val);


	return 0;
}