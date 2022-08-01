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

int arr[10000001];
vector<int> prime;

void primeM()
{
	arr[0] = arr[1] = 1;
	for (long long i = 2; i * i < 10000001; i++) {
		if (arr[i]) {
			continue;
		}
		for (long long j = i * i; j <= 10000000; j += i) {
			arr[j] = 1;
		}
	}
}

void fill()
{
	for (long long i = 2; i < 10000001; i++) {
		if (!arr[i]) {
			prime.push_back(i);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	primeM();
	fill();
	long long a, b;
	long long n;
	int cnt = 0;
	cin >> a >> b;
	
	for (int i = 0; i < prime.size(); i++) {
		n = prime[i];
		while (n <= b / prime[i])
		{
			if (n * prime[i] >= a) {
				//cout << "hi " << n * prime[i] << endl;
				cnt++;
			}
			n *= prime[i];
		}
	}
	cout << cnt;



	return 0;
}