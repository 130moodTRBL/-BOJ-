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

using namespace std;

int main() 
{
	int n;
	int i;
	int choi;
	int sum = 0;
	cin >> n;
	stack<int> stk;
	for (i = 0; i < n; i++) {
		cin >> choi;
		if (choi != 0) {
			stk.push(choi);
			sum += choi;
		}
		else {
			sum -= stk.top();
			stk.pop();
		}
	}
	cout << sum;



	return 0;
}