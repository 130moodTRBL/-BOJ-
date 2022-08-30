#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> ans;
    queue<int> que;
    int cnt = 0;
    
    for(int i = 0; i < progresses.size(); i++) {
        que.push(i);
    }
    
    while(!que.empty())
    {
        cnt = 0;
        for(int i = 0; i < speeds.size(); i++) {
            progresses[i] += speeds[i];
        }
        while(!que.empty())
        {
            int n = que.front();
            if(progresses[n] >= 100) {
                cnt++;
                que.pop();
            }
            else {
                break;
            }
        }
        if(cnt != 0) {
            ans.push_back(cnt);
        }
    }
    return ans;
}