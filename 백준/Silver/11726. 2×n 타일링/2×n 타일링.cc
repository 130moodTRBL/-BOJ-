	#define _CRT_SECURE_NO_WARNINGS
	#include <cstdio>
	#include <iostream>
	#include <stdlib.h>
	#include <stdio.h>
	#include <algorithm>
	#include <cmath>
	#include <string>
	#include <string.h>
	#include <queue>
	#include <stack>
	#include <deque>

	using namespace std;

	int arr[1001];
	int fibonacci(int n)
	{
		if (n <= 2) {
			return n;
		}
		if (arr[n]) {
			return arr[n];
		}

		return arr[n] = (fibonacci(n - 1) + fibonacci(n - 2)) % 10007;
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);

		int n;
		cin >> n;
		cout << fibonacci(n) % 10007;



		return 0;
	}