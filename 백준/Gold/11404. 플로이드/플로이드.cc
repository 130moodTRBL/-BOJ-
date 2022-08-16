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

int arr[101][101];
const int INF = 999999999;

void fill()
{
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (i == j) {
				arr[i][j] = 0;
			}
			else {
				arr[i][j] = INF;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	int a, b, d;
	fill();
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> d;
		arr[a][b] = min(d, arr[a][b]);
		//arr[a][b] = d;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				arr[i][j] = min(arr[i][k] + arr[k][j], arr[i][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == INF) {
				cout << 0 << " ";
			}
			else {
				cout << arr[i][j] << " ";
			}
		}
		cout << endl;
	}





	return 0;
}