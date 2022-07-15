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

const int INF = 30010000;
int arr[1001][1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	int a, b, c;
	int i, j, k;
	cin >> n >> m;

	for (i = 0; i <= n; i++) {
		for (j = 0; j <= n; j++) {
			if (i == j) {
				arr[i][j] = 0;
			}
			else {
				arr[i][j] = INF;
			}
		}
	}
	while (m--)
	{
		cin >> a >> b >> c;
		arr[a][b] = min(c, arr[a][b]);
	}

	for (k = 1; k <= n; k++) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				arr[i][j] = min(arr[i][k] + arr[k][j], arr[i][j]);
			}
		}
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (arr[i][j] == INF) {
				cout << "0" << " ";
			}
			else {
				cout << arr[i][j] << " ";
			}
			
		}
		cout << endl;
	}




	return 0;
}