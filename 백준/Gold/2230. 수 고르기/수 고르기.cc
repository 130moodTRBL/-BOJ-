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

#define endl '\n'

using namespace std;

int arr[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	int en = 0;
	int temp = 2000000001;
	for (int st = 0; st < n; st++) {
		while (en < n && arr[en] - arr[st] < m) {
			en++;
		}
		if (en == n) {
			break;
		}
		temp = min(temp, arr[en] - arr[st]);
	}
	cout << temp;




	return 0;
}