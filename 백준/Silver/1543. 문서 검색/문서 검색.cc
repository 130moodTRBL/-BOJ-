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
#include <tuple>

#define endl '\n'
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str, s;
	int pos = 0;
	int i = 0;
	int ans = 0;
	int cnt = 0;
	getline(cin, str);
	getline(cin, s);

	while (str.find(s) != string::npos)
	{
		ans++;
		str = str.substr(str.find(s) + s.size(), str.size() - str.find(s) - s.size());
	}
	cout << ans;


	return 0;
}