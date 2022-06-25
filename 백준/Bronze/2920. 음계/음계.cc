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

using namespace std;

int arr[8];
int isAscending()
{
	int cnt = 0;
	for (int i = 0; i < 7; i++) {
		if (arr[i + 1] - arr[i] == 1) {
			cnt++;
		}
	}
	if (cnt == 7) {
		return 1;
	}
	else {
		return 0;
	}
}

int isDescending()
{
	int cnt = 0;
	for (int i = 0; i < 7; i++) {
		if (arr[i + 1] - arr[i] == -1) {
			cnt++;
		}
	}
	if (cnt == 7) {
		return 1;
	}
	else {
		return 0;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
	}

	if (isAscending()) {
		cout << "ascending";
	}
	else if (isDescending()) {
		cout << "descending";
	}
	else {
		cout << "mixed";
	}
	
	

	return 0;
}