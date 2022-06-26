#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <queue>
#include <stack>

using namespace std;

int arr[1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int i, j;
	int sum = 0;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (i = 0; i < n; i++) {
		for (j = 0; j <= i; j++) {
			sum += arr[j];
		}
	}
	cout << sum;




	return 0;
}