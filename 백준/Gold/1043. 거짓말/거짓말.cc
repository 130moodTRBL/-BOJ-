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

int parent[1000001];
vector<int> real;
vector<int> arr[1000001];

int getParent(int x)
{
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	if (a > b) {
		parent[a] = b;
	}
	else {
		parent[b] = a;
	}
}

int find(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	if (a == b) {
		return 1;
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, r, x, t;
	cin >> n >> m;
	cin >> r;

	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	while (r--) 
	{
		cin >> x;
		real.push_back(x);
	}
	int temp;
	for (int i = 0; i < m; i++) {
		cin >> t;
		for (int j = 0; j < t; j++) {
			cin >> x;
			arr[i].push_back(x);
			if (j > 0) {
				unionParent(x, temp);
			}
			temp = x;
		}
	}

	int num;
	int check = 0;
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		num = getParent(arr[i][0]);
		check = 0;
		for (int j = 0; j < real.size(); j++) {
			if (num == getParent(real[j])) {
				check = 1;
			}
		}
		if (check == 0) {
			cnt++;
		}
		check = 0;
	}
	cout << cnt;
	
	
	/*for (int i = 0; i < m; i++) {
		vector<int> temp;
		check = 0;
		for (int j = 0; j < arr[i].size(); j++) {
			temp.push_back(j);
		}
		for (int j = 0; j < temp.size(); j++) {
			for (int k = 0; k < real.size(); k++) {
				if (find(temp[j], real[k])) {
					check = 1;
				}
			}
		}
		if (check == 0) {
			cnt++;
		}
	}
	cout << cnt;*/



	return 0;
}