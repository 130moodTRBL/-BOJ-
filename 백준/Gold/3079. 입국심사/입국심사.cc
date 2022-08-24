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

long long n, m;
long long arr[100001];

long long sol()
{
	long long low, mid, hig;
	long long sum = 0;
	low = 0;
	hig = arr[n - 1] * m;
	while (low <= hig)
	{
		mid = (low + hig) / 2;
		sum = 0;
		//cout << mid << endl;
		for (int i = 0; i < n; i++) {
			sum += (mid / arr[i]);
		}
		if (sum >= m) {
			hig = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	//cout << low << " " << hig << endl;
	return low;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	cout << sol();




	return 0;
}