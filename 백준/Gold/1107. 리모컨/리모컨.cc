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

int arr[111];

int check(int n)
{
	if (n == 0) {
		if (arr[0]) {
			return 0;
		}
		else {
			return 1;
		}
	}
	int len = 0;
	while (n > 0) {
		if (arr[n % 10]) {
			return 0;
		}
		n = n / 10;
		len += 1;
	}

	return len;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	int x;
	int i, j;
	int len;
	int result;
	int cnt = 0;

	cin >> n;
	cin >> m;

	for (i = 0; i < m; i++) {
		cin >> x;
		arr[x] = 1;
	}

	result = abs(100 - n);
	for (i = 0; i <= 1000000; i++) {
		len = check(i);
		if (len > 0) {
			cnt = abs(i - n);
			if (result > cnt + len) {
				result = cnt + len;
			}
		}
	}
	cout << result;

	


	return 0;
}