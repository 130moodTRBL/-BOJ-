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

int arr[505050];

void primeM()
{
	arr[0] = arr[1] = 1;
	for (int i = 2; i * i < 505050; i++) {
		if (arr[i]) {
			continue;
		}
		for (int j = i * i; j <= 505050; j += i) {
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
	int cnt;
	primeM();
	while (1)
	{
		cin >> n;
		cnt = 0;
		if (n == 0) {
			break;
		}
		for (int i = n + 1; i <= 2 * n; i++) {
			if (!arr[i]) {
				cnt++;
			}
		}
		cout << cnt << endl;
	}
 	



	return 0;
}