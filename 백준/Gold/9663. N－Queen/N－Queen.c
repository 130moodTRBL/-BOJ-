#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int n;
bool flag_a[15];
bool flag_b[29];
bool flag_c[29];
int cnt = 0;

void queen(int col, int n)
{
	if (col == n) {
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (flag_a[i] == false && flag_b[i + col] == false && flag_c[col - i + n - 1] == false) {
			flag_a[i] = flag_b[i + col] = flag_c[col - i + n - 1] = true;
			queen(col + 1, n);
			flag_a[i] = flag_b[i + col] = flag_c[col - i + n - 1] = false;
		}
	}
	
}

int main()
{
	scanf("%d", &n);
	queen(0, n);
	printf("%d\n", cnt);


	return 0;
}
