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

using namespace std;

long long GCD(long long a, long long b)
{
	if (b == 0) {
		return a;
	}
	return GCD(b, a % b);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long a, b;
	long long temp;
	cin >> a >> b;

	if (a > b) {
		temp = GCD(a, b);
	}
	else {
		temp = GCD(b, a);
	}
	
	for (int i = 0; i < temp; i++) {
		cout << 1;
	}



	return 0;
}