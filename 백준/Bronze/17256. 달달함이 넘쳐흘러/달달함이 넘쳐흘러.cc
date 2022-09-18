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
#include <set>

#define endl '\n'
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b, c;
	int x, y, z;
	cin >> a >> b >> c;
	cin >> x >> y >> z;
	cout << x - c << " " << y / b << " " << z - a;



	return 0;
}