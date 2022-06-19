#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;
int start[100001];
int last[100001];

void insertionSort(int n)
{
	int i, j, tempS, tempL;
	for (i = 1; i < n; i++) {
		tempS = start[i];
		tempL = last[i];
		for (j = i - 1; j >= 0 && tempS < start[j]; j--) {
			start[j + 1] = start[j];
			last[j + 1] = last[j];
		}
		start[j + 1] = tempS;
		last[j + 1] = tempL;
	}
}

int main() 
{
	/*int n;
	int i, j;
	int cnt = 0;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> start[i] >> last[i];
	}
	insertionSort(n);*/
	char c[101];
	int i = 0;
	cin >> c;
	while (c[i] != NULL) {
		i++;
	}
	cout << i;


		

	return 0;
}