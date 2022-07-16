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

int arrA[1001][1001];
int arrB[1001][1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);	
	cout.tie(0);

	int n, m;
	int a;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arrA[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a;
			arrA[i][j] += a;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arrA[i][j] << " ";
		}
		cout << endl;
	}





	return 0;
}