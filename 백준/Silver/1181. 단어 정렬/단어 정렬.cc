#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
string word[20000];

int main()
{
	int n;
	int i, j;
	
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> word[i];
	}
	sort(word, word + n, [](string a, string b)->bool {
		if (a.size() != b.size()) return a.size() < b.size();
		else return a < b;
		});

	for (i = 0; i < n - 1; i++) {
		if (word[i] != word[i + 1]) {
			cout << word[i] << endl;
		}
	}
	cout << word[n - 1] << endl;



	return 0;
}