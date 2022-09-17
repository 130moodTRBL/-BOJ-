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
#include <deque>

#define endl '\n'
using namespace std;

int arr[101];
vector<stack<int>> pass;
int port[101][101];
int key[101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	
	int check = 0;
	
	for (int i = 1; i <= n; i++) {
		check = 0;
		for (int j = 1; j <= k; j++) {	
			if (port[j][key[j]] < arr[i]) {
				key[j]++;
				port[j][key[j]] = arr[i];
				check = 1;
				break;
			}
		}
		if (check == 0) {
			cout << "NO";
			exit(0);
		}
	}
	cout << "YES";


	




	return 0;
}