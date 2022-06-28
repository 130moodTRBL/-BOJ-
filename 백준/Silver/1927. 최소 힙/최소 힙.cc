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

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	priority_queue<int, vector<int>, greater<int>> que;
	int t, choi;

	cin >> t;
	while (t--)
	{
		cin >> choi;
		if (choi == 0) {
			if (que.empty()) {
				//cout << 0 << endl;
				printf("%d\n", 0);
			}
			else {
				//cout << que.top() << endl;
				printf("%d\n", que.top());
				que.pop();
			}
		}
		else {
			/*if (choi < 0) {
				choi = -choi;
			}*/
			que.push(choi);
		}
	}



	return 0;
}