#include <string>
#include <vector>

using namespace std;

int flag[101];
int arr[101];
char pm[] = {'+', '-'};
int m;
int ans = 0;
int tar;
vector<int> nums;

void sol()
{
    int sum = 0;
    for(int i = 0; i < m; i++) {
        if((char)arr[i] == '+') {
            sum += nums[i];
        }
        else if ((char)arr[i] == '-') {
            sum -= nums[i];
        }
    }
    if(sum == tar) {
        ans++;
    }
}

void backT(int level)
{
    if(level == m) {
        sol();
        return;
    }
    for(int i = 0; i < 2; i++) {
        if(flag[level] == 0) {
            flag[level] = 1;
            arr[level] = pm[i];
            
            backT(level + 1);
            
            flag[level] = 0;
            arr[level] = 0;
        }
    }
}

int solution(vector<int> numbers, int target) {
    m = numbers.size();
    nums = numbers;
    tar = target;
    backT(0);
    
    return ans;
}