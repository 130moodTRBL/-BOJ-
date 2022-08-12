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

	string s;
	stack<char> stk;
	int check = 0;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		//cout << check << endl;
		stk.push(s[i]);
		if (s[i] == 'P') {
			check++;
		}
		else if (check >= 2 && s[i + 1] == 'P') {
			for (int j = 0; j < 2; j++) {
				stk.pop();
			}
			i++;
			check--;
		}
	}
	//cout << temp << endl;
	if (stk.top() == 'P' && stk.size() == 1) {
		cout << "PPAP";
	}
	else {
		cout << "NP";
	}



	return 0;
}