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

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	unsigned long long n;
	cin >> n;

	if (n == 0) {
		cout << 0;
		exit(0);
	}

	unsigned long long s, e;
	s = 2;
	e = 1;
	for (int i = 1; i <= n; i++) {
		unsigned long long sum = i;
		for (int j = 0; j <= i; j++) {
			unsigned long long temp = sum + 1;
			sum += temp;
		}
		e = sum;
		//cout << "e: " << sum << endl;
		if (n >= s && n <= e) {
			cout << i;
			exit(0);
		}
		//cout << s << ' ' << e << endl;
		s = e + 1;
	}




	return 0;
}