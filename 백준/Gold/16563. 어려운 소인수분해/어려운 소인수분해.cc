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

#define endl '\n'

using namespace std;

int arr[5000001];
int prime[5000001];

void makePrime()
{
	prime[0] = 1;
	prime[1] = 1;

	for (int i = 2; i < 5000001; i++) {
		prime[i] = i;
	}

	for (int i = 2; i <= sqrt(5000001); i++) {
		if (prime[i] == i) {
			for (int j = i * i; j < 5000001; j += i) {
				if (prime[j] == j) {
					prime[j] = i;
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	int i, j, k;
	int temp;
	makePrime();

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		temp = arr[i];
		while (temp != 1) {
			cout << prime[temp] << " ";
			temp = temp / prime[temp];
		}
		cout << endl;
	}

	return 0;
}