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
#include <set>
#include <deque>

#define endl '\n'
using namespace std;

int arr[12] = { 0,1,4,6,8,9,10,12,14,15,16,18 };

int combination(int n, int r)
{
	if (n == r || r == 0) {
		return 1;
	}	
	else {
		return combination(n - 1, r - 1) + combination(n - 1, r);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b;
	cin >> a >> b;

	double ap = a / 100.0;
	double bp = b / 100.0;

	double sumA = 0;
	double sumB = 0;
	for (int i = 0; i < 12; i++) {
		long long temp = 0;
		temp = combination(18, arr[i]);
		sumA += temp * (pow(ap, arr[i]) * pow(1 - ap, 18 - arr[i]));
		sumB += temp * (pow(bp, arr[i]) * pow(1 - bp, 18 - arr[i]));
	}

	cout << 1 - (sumA * sumB);

	

	return 0;
}