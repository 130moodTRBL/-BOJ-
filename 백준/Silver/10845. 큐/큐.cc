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

using namespace std;

int main() 
{
	queue<int> que;
	string s;
	int n, temp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "push") {
			cin >> temp;
			que.push(temp);
		}
		else if (s == "pop") {
			if (que.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << que.front() << endl;
				que.pop();
			}
		}
		else if (s == "size") {
			cout << que.size() << endl;
		}
		else if (s == "empty") {
			if (que.empty()) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else if (s == "front") {
			if (que.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << que.front() << endl;
			}
		}
		else if (s == "back") {
			if(que.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << que.back() << endl;
			}
		}
	}



	return 0;
}