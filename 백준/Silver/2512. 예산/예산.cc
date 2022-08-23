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

int arr[1000001];
int n, m;

int sol()
{
	long long low, mid, hig;
	long long sum = 0;
	low = 1;
	hig = arr[n - 1];
	while (low <= hig)
	{
		mid = (low + hig) / 2;
		sum = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] >= mid) {
				sum += mid;
			}
			else {
				sum += arr[i];
			}
		}
		if (sum <= m) {
			low = mid + 1;
		}
		else {
			hig = mid - 1;
		}
	}
	//cout << hig << " " << low << endl;
	return hig;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> m;
	sort(arr, arr + n);
	cout << sol();



	return 0;
}