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

int arr[100001];
int vis[100001];
vector<int> prime;

void primeM()
{
	arr[0] = arr[1] = 1;
	for (int i = 2; i * i < 100001; i++) {
		if (arr[i]) {
			continue;
		}
		for (int j = i * i; j <= 100000; j += i) {
			arr[j] = 1;
		}
	}
}

void fill()
{
	for (int i = 2; i < 100001; i++) {
		if (!arr[i]) {
			prime.push_back(i);
		}
	}
}

void mem()
{
	for (int i = 0; i < 100001; i++) {
		vis[i] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	int n;
	int pos;
	primeM();
	fill();
	cin >> t;
	while (t--)
	{
		mem();
		cin >> n;
		pos = 0;
		while (1)
		{
			if (n == 1) {
				break;
			}
			if (n % prime[pos] == 0) {
				n /= prime[pos];
				vis[prime[pos]]++;
			}
			else {
				pos++;
			}
		}

		for (int i = 2; i < 100001; i++) {
			if (vis[i] > 0) {
				cout << i << " " << vis[i] << endl;
			}
		}
	}




	return 0;
}