#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int n, l;
	int arr[1001];
	int pipe[1001] = { 0 };
	int i;
	int temp = 0;
	int cnt = 1;
	cin >> n >> l;
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	temp = arr[0];
	for (i = 0; i < n; i++) {
		if (arr[i] - temp > l - 1) {
			temp = arr[i];
			cnt++;
		}
	}
	cout << cnt;



	return 0;
}