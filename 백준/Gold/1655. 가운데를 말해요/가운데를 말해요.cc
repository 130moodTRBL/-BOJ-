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
#include <unordered_map>

#define endl '\n'
using namespace std;

priority_queue<int, vector<int>, greater<int>> sec;
priority_queue<int> fir;
vector<int> arr;
//
//void fillF()
//{
//	int n;
//	while (!que.empty())
//	{
//		n = que.top();
//		que.pop();
//		arr.push_back(n);
//		//cout << "que: " << n << endl;
//	}
//}
//
//void fillE()
//{
//	int n;
//	for (int i = arr.size() - 1; i >= 0; i--) {
//		que.push(arr[i]);
//		arr.pop_back();
//	}
//}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, x;
	cin >> n;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (sec.size() < fir.size()) {
			sec.push(x);
		}
		else {
			fir.push(x);
		}
		if (!fir.empty() && !sec.empty() && sec.top() < fir.top()) {
			a = fir.top();
			b = sec.top();
			fir.pop();
			sec.pop();
			fir.push(b);
			sec.push(a);
		}
		cout << fir.top() << endl;
	}




	return 0;
}