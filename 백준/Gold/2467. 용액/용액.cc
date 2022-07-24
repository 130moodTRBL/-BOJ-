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
#include <tuple>

#define endl '\n'

using namespace std;

int arr[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	int sum = 0;
	int ans = 2000000000;
	int tempA, tempB;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int st = 0;
	int en = n - 1;
	int temp;
	tempA = arr[st];
	tempB = arr[en];
	while (st < en) 
	{
		sum = arr[st] + arr[en];
		temp = sum;
		if (abs(temp) < ans) {
			ans = abs(temp);
			tempA = arr[st];
			tempB = arr[en];
		}
		if (sum < 0) {
			st++;
		}
		else {
			en--;
		}
	}
	cout << tempA << " " << tempB;
	



	return 0;
}