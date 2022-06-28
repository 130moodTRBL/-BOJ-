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

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	priority_queue<int, vector<int>, greater<int>> queP;
	priority_queue<int, vector<int>, less<int>> queM;
	int t, choi;

	cin >> t;
	while (t--)
	{
		cin >> choi;
		if (choi == 0) {
			if (queP.empty() && queM.empty()) {
				printf("%d\n", 0);
			}
			else {
				if (queP.empty()) {
					printf("%d\n", queM.top());
					queM.pop();
				}
				else if (queM.empty()) {
					printf("%d\n", queP.top());
					queP.pop();
				}
				else if (queP.top() >= -queM.top()) {
					printf("%d\n", queM.top());
					queM.pop();
				}
				else if (queP.top() < -queM.top()) {
					printf("%d\n", queP.top());
					queP.pop();
				}
			}
		}
		else {
			if (choi < 0) {
				queM.push(choi);
			}
			else {
				queP.push(choi);
			}
		}
	}



	return 0;
}