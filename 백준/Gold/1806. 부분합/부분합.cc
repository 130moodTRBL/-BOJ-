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

	int n, s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int cnt = 0;
	int temp = 100000001;
	int en = 0;
	int sum = arr[0];
	for (int st = 0; st < n; st++) {
		while (en < n && sum < s) {
			en++;
			if (en != n) {
				sum += arr[en];
			}
		}
		if (en == n) {
			break;
		}
		temp = min(temp, en - st + 1);
		sum -= arr[st];
	}
	if (temp == 100000001) {
		cout << 0;
	}
	else {
		cout << temp;
	}
	



	return 0;
}