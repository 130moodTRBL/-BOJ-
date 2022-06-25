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

using namespace std;
int arr[1000001];

int fibonacci(int n)
{
	if (n <= 1) {
		return n;
	}
	if (arr[n]) {
		return arr[n];
	}

	return arr[n] = (fibonacci(n - 1) + fibonacci(n - 2)) % 1000000000;
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	if (n < 0) {
		n = -n;
		if (n % 2 == 0) {
			cout << -1 << endl;
		}
		else {
			cout << 1 << endl;
		}
	}
	else if (n > 0) {
		cout << 1 << endl;
	}
	else {
		cout << 0 << endl;
	}
	cout << fibonacci(n) % 1000000000;




	return 0;
}