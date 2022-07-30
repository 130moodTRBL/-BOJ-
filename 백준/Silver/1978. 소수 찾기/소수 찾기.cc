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

int arr[1001];
vector<int> prime;

void primeM()
{
	arr[0] = arr[1] = 1;
	for (int i = 2; i * i < 1001; i++) {
		if (arr[i]) {
			continue;
		}
		for (int j = i * i; j <= 1000; j += i) {
			arr[j] = 1;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	int x;
	int cnt = 0;
	cin >> n;
	primeM();
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (!arr[x]) {
			cnt++;
		}
	}
	cout << cnt;
 	



	return 0;
}