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

using namespace std;

#define endl '\n'

long long arr[10001];
queue<int> que;
queue<string> ans;

void fill()
{
	for (int i = 0; i < 10001; i++) {
		arr[i] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	int pos = 0;
	long long n, num;
	long long x;
	long long tempX, tempY;
	while (1)
	{
		vector<string> order;
		fill();
		pos = 0;
		while (1)
		{
			cin >> s;
			if (s == "QUIT") {
				exit(0);
			}
			if (s == "NUM") {
				cin >> num;
				arr[pos++] = num;
			}
			if (s == "END") {
				break;
			}
			order.push_back(s);
		}
		cin >> n;
		for (int i = 0; i < n; i++) {
			stack<long long> stk;
			pos = 0;
			cin >> x;
			stk.push(x);
			for (int j = 0; j < order.size(); j++) {
				if (order[j] == "NUM") {
					num = arr[pos++];
					stk.push(num);
				}
				else if (order[j] == "POP") {
					if (stk.empty()) {
						stk.push(1000000001);
						break;
					}
					else {
						stk.pop();
					}
				}
				else if (order[j] == "INV") {
					if (stk.empty()) {
						stk.push(1000000001);
						break;
					}
					else {
						num = stk.top();
						stk.pop();
						stk.push(-num);
					}
				}
				else if (order[j] == "DUP") {
					if (stk.empty()) {
						stk.push(1000000001);
						break;
					}
					else {
						num = stk.top();
						stk.push(num);
					}
				}
				else if (order[j] == "SWP") {
					if (stk.empty()) {
						stk.push(1000000001);
						break;
					}
					else {
						tempX = stk.top();
						stk.pop();
					}
					
					if (stk.empty()) {
						stk.push(1000000001);
						break;
					}
					else {
						tempY = stk.top();
						stk.pop();
						stk.push(tempX);
						stk.push(tempY);
					}
				}
				else if (order[j] == "ADD") {
					if (stk.empty()) {
						stk.push(1000000001);
						break;
					}
					else {
						tempX = stk.top();
						stk.pop();
					}
					
					if (stk.empty()) {
						stk.push(1000000001);
						break;
					}
					else {
						tempY = stk.top();
						stk.pop();
					}
					if (abs(tempX + tempY) > 1000000000) {
						stk.push(1000000001);
						break;
					}
					else {
						stk.push(tempX + tempY);
					}
				}
				else if (order[j] == "SUB") {
					if (stk.empty()) {
						stk.push(1000000001);
						break;
					}
					else {
						tempX = stk.top();
						stk.pop();
					}
					
					if (stk.empty()) {
						stk.push(1000000001);
						break;
					}
					else {
						tempY = stk.top();
						stk.pop();
					}
					if (abs(tempX - tempY) > 1000000000) {
						stk.push(1000000001);
						break;
					}
					else {
						stk.push(tempY - tempX);
					}
				}
				else if (order[j] == "MUL") {
					if (stk.empty()) {
						stk.push(1000000001);
						break;
					}
					else {
						tempX = stk.top();
						stk.pop();
					}
					
					if (stk.empty()) {
						stk.push(1000000001);
						break;
					}
					else {
						tempY = stk.top();
					stk.pop();
					}
					
					if (abs(tempX * tempY) > 1000000000) {
						stk.push(1000000001);
						break;
					}
					else {
						stk.push(tempX * tempY);
					}
				}
				else if (order[j] == "DIV") {
					if (stk.empty()) {
						stk.push(1000000001);
						break;
					}
					else {
						tempX = stk.top();
						stk.pop();
					}
					
					if (stk.empty()) {
						stk.push(1000000001);
						break;
					}
					else {
						tempY = stk.top();
						stk.pop();
					}
					if (tempX == 0) {
						stk.push(1000000001);
						break;
					}
					else {
						stk.push(tempY / tempX);
					}
				}
				else if (order[j] == "MOD") {
					if (stk.empty()) {
						stk.push(1000000001);
						break;
					}
					else {
						tempX = stk.top();
						stk.pop();
					}
					
					if (stk.empty()) {
						stk.push(1000000001);
						break;
					}
					else {
						tempY = stk.top();
						stk.pop();
					}
					
					if (tempX == 0) {
						stk.push(1000000001);
						break;
					}
					else {
						stk.push(tempY % tempX);
					}
				}
			}
			int check = 0;
			if (stk.empty()) {
				ans.push("ERROR");
				check = 1;
			}
			else {
				for (int i = 0; i < stk.size(); i++) {
					if (stk.size() != 1 || stk.top() > 1000000000) {
						ans.push("ERROR");
						check = 1;
						break;
					}
				}
			}
			
			if (check == 0) {
				string s = to_string(stk.top());
				ans.push(s);
			}
		}
		while (!ans.empty())
		{
			string fin = ans.front();
			ans.pop();
			cout << fin << endl;
		}
		cout << endl;
	}
	



	return 0;
}