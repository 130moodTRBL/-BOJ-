#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <tuple>

#define endl '\n'
using namespace std;

int arr[1000001];

int uclid(int a, int b)
{
	if (b == 0) {
		return a;
	}
	return uclid(b, a % b);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		long long sum = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (arr[i] > arr[j]) {
					sum += uclid(arr[i], arr[j]);
				}
				else {
					sum += uclid(arr[j], arr[i]);
				}
			}
		}
		cout << sum << endl;
	}




	return 0;
}