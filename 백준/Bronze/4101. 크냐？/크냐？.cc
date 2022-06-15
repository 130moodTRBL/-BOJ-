#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main()
{
	int a, b;
	while (1)
	{
		cin >> a >> b;
		if (a == 0 && b == 0)
			break;
		if (a > b) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}
	



	return 0;
}