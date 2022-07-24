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
#include <tuple>

#define endl '\n'

using namespace std;

long long arr[100001];
long long fin[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	long long sum = 0;
	long long ans = 3000000001;
	int tempA, tempB, tempM;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int st;
	int en;
	int temp;
	for (int i = 0; i < n; i++) {
		st = i + 1;
		en = n - 1;
		while (st < en)
		{
			sum = arr[st] + arr[en] + arr[i];
			if (abs(sum) < ans) {
				ans = abs(sum);
				tempA = arr[st];
				tempB = arr[en];
				tempM = arr[i];
			}
			if (sum < 0) {
				st++;
			}
			else {
				if (en - 1 == i) {
					en -= 2;
				}
				else {
					en--;
				}
			}
		}
	}
	cout << tempM << " " << tempA << " " << tempB;



	return 0;
}