#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <stdlib.h>
#include <algorithm>

using namespace std;

void sol(int arr[], int sum)
{
	int temp = sum;
	int i, j, k;
	int a, b;
	for (i = 0; i < 8; i++) {
		for (j = i + 1; j < 9; j++) {
			sum = temp;
			sum -= arr[i];
			sum -= arr[j];
			if (sum == 100) {
				a = arr[i];
				b = arr[j];
				sort(arr, arr + 9);
				for (k = 0; k < 9; k++) {
					if (arr[k] == a || arr[k] == b) {
						continue;
					}
					printf("%d\n", arr[k]);
				}
				return;
			}
		}
	}

}

int main()
{
	int arr[9];
	int sum = 0;
	int temp;
	for (int i = 0; i < 9; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	sol(arr, sum);
	

	return 0;
}