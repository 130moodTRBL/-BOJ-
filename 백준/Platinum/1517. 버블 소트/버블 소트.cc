#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;
int arr[500001];
int sorted[500001];
long long val = 0;

void merges(int left, int right) 
{
	int mid = (left + right) / 2;
	int i = left;
	int j = mid + 1;
	int k = left;
	long long cnt = 0;

	while (i <= mid && j <= right) 
	{
		if (arr[i] <= arr[j]) {
			sorted[k++] = arr[i++];
			val += cnt;
		}
		else {
			sorted[k++] = arr[j++];
			cnt++;
		}
	}

	if (i > mid) {
		while (j <= right) 
		{
			sorted[k++] = arr[j++];
			cnt++;
		}
	}
	else {
		while (i <= mid) 
		{;
			sorted[k++] = arr[i++];
			val += cnt;
		}
	}

	for (int a = left; a <= right; a++) {
		arr[a] = sorted[a];
	}
}

void mergeSort(int left, int right) 
{
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		mergeSort(left, mid);
		mergeSort(mid + 1, right);
		merges(left, right);
	}
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	mergeSort(0, N - 1);
	cout << val;

	return 0;
}