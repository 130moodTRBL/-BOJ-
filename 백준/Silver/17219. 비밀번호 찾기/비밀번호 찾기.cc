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

#define endl '\n'

using namespace std;

map<string, string> arr;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	string site, password;
	string s;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> site >> password;
		arr[site] = password;
	}
	
	for (int i = 0; i < m; i++) {
		cin >> s;
		cout << arr[s] << endl;
	}

	

	return 0;
}