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

#define endl '\n'

using namespace std;

char lc[1000];
char rc[1000];

void preorder(int cur)
{
	cout << char(cur + 'A' - 1);
	if (lc[cur]) {
		preorder(lc[cur]);
	}
	if (rc[cur]) {
		preorder(rc[cur]);
	}
} 

void inorder(int cur)
{
	if (lc[cur]) {
		inorder(lc[cur]);
	}
	cout << char(cur + 'A' - 1);
	if (rc[cur]) {
		inorder(rc[cur]);
	}
}

void postorder(int cur)
{
	if (lc[cur]) {
		postorder(lc[cur]);
	}
	if (rc[cur]) {
		postorder(rc[cur]);
	}
	cout << char(cur + 'A' - 1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	char a, b, c;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		if (b != '.') {
			lc[a - 'A' + 1] = b - 'A' + 1;
		}
		if (c != '.') {
			rc[a - 'A' + 1] = c - 'A' + 1;
		}
	}
	preorder(1);
	cout << endl;
	inorder(1);
	cout << endl;
	postorder(1);
	cout << endl;

	



	return 0;
}