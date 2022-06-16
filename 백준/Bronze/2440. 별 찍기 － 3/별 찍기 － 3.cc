#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = n; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			cout << "*";
		}
		cout << "\n";
	}


	return 0;
}