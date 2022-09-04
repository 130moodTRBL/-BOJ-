#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string ans = "";

    int idx = -1;
    for(int i = 0; i < number.length() - k; i++){
        char temp = '0';
        for(int j = idx + 1; j <= k + i; j++){
            if(temp < number[j]) {
                temp = number[j];
                idx = j;
            }
        }
        ans += temp;
    }
    
    return ans;
}