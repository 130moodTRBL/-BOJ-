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

int arr[100001];
int n, m;
int flag = -1;

int sol()
{
	long long low, mid, hig;
	long long cnt = 1;
	long long temp;
	low = flag;
	hig = 1000000000;
	while (low <= hig)
	{
		mid = (low + hig) / 2;
		temp = mid;
		cnt = 1;
		for (int i = 0; i < n; i++) {
			if (arr[i] > temp) {
				cnt++;
				temp = mid;
			}
			temp -= arr[i];
		}
		if (cnt <= m) {
			hig = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	//cout << hig << " " << low << endl;
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
		flag = max(flag, arr[i]);
	}
	//sort(arr, arr + n);
	cout << sol();



	return 0;
}