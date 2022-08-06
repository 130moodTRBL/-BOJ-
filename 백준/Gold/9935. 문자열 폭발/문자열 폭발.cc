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

	string str, s;
	string temp;
	int pos = 0;
	int cnt = 0;
	cin >> str >> s;
	for (int i = 0; i < str.length(); i++) {
		temp += str[i];
		if (s[s.length() - 1] == temp[temp.length() - 1] && temp.length() >= s.length() - 1) {
			cnt = 0;
			//cout << temp[temp.length() - 1] << endl;
			//cout << temp << endl;
			for (int j = s.length() - 1; j >= 0; j--) {
				if (temp[temp.length() - 1 -(s.length()-j - 1)] == s[j]) {
					cnt++;
				}
			}
			//cout << "cnt: " << cnt << endl;
			if (cnt == s.length()) {
				//temp = temp.substr(0, temp.find(s));
				for (int k = 0; k < s.length(); k++) {
					temp.pop_back();
				}
			}
		}
	}
	if (temp == "") {
		cout << "FRULA";
	}
	else {
		cout << temp;
	}
	/*AAZB
	AB
	AAZB*/


	return 0;
}