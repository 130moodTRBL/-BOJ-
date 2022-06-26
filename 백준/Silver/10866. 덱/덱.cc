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

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	deque<int> dq;
	int n, temp;
	string s;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "push_front") {
			cin >> temp;
			dq.push_front(temp);
		}
		else if (s == "push_back") {
			cin >> temp;
			dq.push_back(temp);
		}
		else if (s == "pop_front") {
			if (dq.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << dq.front() << endl;
				dq.pop_front();
			}
		}
		else if (s == "pop_back") {
			if (dq.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << dq.back() << endl;
				dq.pop_back();
			}
		}
		else if (s == "size") {
			cout << dq.size() << endl;
		}
		else if (s == "empty") {
			if (dq.empty()) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else if (s == "front") {
			if (dq.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << dq.front() << endl;
			}
		}
		else if (s == "back") {
			if (dq.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << dq.back() << endl;
			}
		}
	}



	return 0;
}