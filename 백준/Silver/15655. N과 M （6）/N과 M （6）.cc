#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int n, m;
int arr[8];
int flag[9] = { 0, };
int brr[8];
void recursive(int num, int level)
{
	int i;
	if (level == m) {
		for (i = 0; i < m; i++) {
			printf("%d ", brr[i]);
		}
		printf("\n");
		return;
	}

	for (i = num; i < n; i++) {
		if (flag[i + 1] == 0) {
			brr[level] = arr[i];
			flag[i + 1] = 1;
			recursive(i + 1, level + 1);		//1 7 8 9
			brr[level] = 0;
			flag[i + 1] = 0;
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	recursive(0, 0);

	return 0;
}