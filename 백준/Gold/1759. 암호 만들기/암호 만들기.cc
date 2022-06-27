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

using namespace std;

int l, c;

char arr[15];
char word[15];
int flag[1000];

void password(int level, int num)
{
	int i;
	int cntM = 0;
	int cntJ = 0;
	if (level == l)
	{
		cntM = 0;
		cntJ = 0;
		for (i = 0; i < l; i++)
		{
			if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
				cntM++;
			}
			if (word[i] != 'a' && word[i] != 'e' && word[i] != 'i' && word[i] != 'o' && word[i] != 'u') {
				cntJ++;
			}
		}
		if (cntM != 0 && cntJ >= 2) {
			for (i = 0; i < l; i++) {
				cout << word[i];
			}
			cout << endl;
			return;
		}
		return;
	}

	for (i = num; i < c; i++)
	{
		if (flag[arr[i]] == 0)
		{
			word[level] = arr[i];
			flag[arr[i]] = 1;						//a c i s t w
			password(level + 1, i + 1);
			word[level] = 0;
			flag[arr[i]] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int cnt = 0;
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + c);
	
	password(0, 0);



	return 0;
}