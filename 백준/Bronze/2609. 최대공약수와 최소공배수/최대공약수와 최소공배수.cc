#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

int GCD(int a, int b)
{
	if (b == 0) {
		return a;
	}
	return GCD(b, a % b);
}

int main() 
{
	int a, b;
	cin >> a >> b;
	int n;
	if (a > b) {
		n = GCD(a, b);
	}
	else {
		n = GCD(b, a);
	}
	cout << n << endl;
	cout << a * b / n << endl;



	return 0;
}