#include <stdio.h>

//using namespace std;

int dp[100001];
int arr[100001];

int main() 
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);

	int n, m;
	int a, b;
	//cin >> n >> m;
	scanf("%d %d", &n, &m);

	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		//cin >> arr[i];
		scanf("%d", &arr[i]);
		dp[i] = dp[i - 1] + arr[i];
	}

	for (int i = 0; i < m; i++) {
		//cin >> a >> b;
		scanf("%d %d", &a, &b);
		//cout << dp[b] - dp[a - 1] << endl;
		printf("%d\n", dp[b] - dp[a - 1]);
	}



	return 0;
}