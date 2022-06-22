#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <stack>

using namespace std;


int main() 
{
	int n;
	int temp;
	string s;
	stack<int> stk;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "push") {
			cin >> temp;
			stk.push(temp);
		}
		else if (s == "pop") {
			if (stk.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << stk.top() << endl;
				stk.pop();
			}
		}
		else if (s == "size") {
			cout << stk.size() << endl;
		}
		else if (s == "empty") {
			if (stk.empty()) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else if (s == "top") {
			if (stk.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << stk.top() << endl;
			}
		}
		
	}



	return 0;
}