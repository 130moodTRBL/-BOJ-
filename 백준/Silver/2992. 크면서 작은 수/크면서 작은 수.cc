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
vector<int> arr;
int temp[10];
int flag[10];
int ans = 999999999;
int n;

void sol(int level)
{
	string s;
	int num;
	if (level == arr.size()) {
		for (int i = 0; i < arr.size(); i++) {
			s.push_back(temp[i] + 48);
		}
		num = stoi(s);
		if (num > n) {
			//printf("num: %d, n: %d\n", num, n);
			ans = min(ans, num);
		}
		
		return;
	}

	for (int i = 0; i < arr.size(); i++) {
		if (flag[i + 1] == 0) {
			temp[level] = arr[i];
			flag[i + 1] = 1;
			sol(level + 1);
			temp[level] = 0;
			flag[i + 1] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;
	n = stoi(str);
	int temp = n;
	while (temp > 0)
	{
		arr.push_back(temp % 10);
		temp /= 10;
	}
	sort(arr.begin(), arr.end());
	sol(0);
	if (ans == 999999999) {
		cout << 0;
	}
	else {
		cout << ans;
	}


	return 0;
}