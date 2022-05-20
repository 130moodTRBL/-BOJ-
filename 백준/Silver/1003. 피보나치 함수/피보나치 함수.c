#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int arr[41];
int fibonacci(int n)
{
	if (arr[n] != 0) {
		arr[0] = 0;
		return arr[n];
	}
	if (n == 0) {
		arr[1] = 1;
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	return arr[n] = fibonacci(n - 1) + fibonacci(n - 2);

}

int main()
{
	int t, n;
	
	scanf("%d", &t);
	//printf("%d", fibonacci(t));

	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		fibonacci(n);
		if (n == 1)
			printf("%d %d\n", 0, 1);
		else if (n == 0)
			printf("%d %d\n", 1, 0);
		else
			printf("%d %d\n", arr[n - 1], arr[n]);
	}


	return 0;
}
