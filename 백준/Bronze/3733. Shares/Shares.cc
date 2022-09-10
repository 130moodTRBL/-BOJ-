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

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, s;
	while (cin >> n >> s)
	{
		cout << s / (n + 1) << endl;
	}




	return 0;
}