#include <string>
#include <vector>
#include <queue>
// #include <functional>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<long long, vector<long long>, greater<long long>> que;
    long long cnt = 0;
    long long f, s, mix;
    int check = 0;
    
    for(int i = 0; i < scoville.size(); i++) {
        que.push(scoville[i]);
    }
    
    int n = scoville.size();
    while(n--)
    {
        if(que.top() >= K) {
            return cnt;
        }
        
        if(!que.empty()) {
            f = que.top();
            que.pop();
            check++;
        }
        
        if(!que.empty()) {
            s = que.top();
            que.pop();
            check++;
        }
        
        mix = f + (s * 2);
        que.push(mix);
        cnt++;
        check--;
    }
    
    return -1;
}