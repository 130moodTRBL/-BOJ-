#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main()
{
	int n, k;
	int arr[10];
	int cnt = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] <= k) {
			cnt += k / arr[i];
			k = k % arr[i];
		}
	}
	cout << cnt << "\n";




	return 0;
}