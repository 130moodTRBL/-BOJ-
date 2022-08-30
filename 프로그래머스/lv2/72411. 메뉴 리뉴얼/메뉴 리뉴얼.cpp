#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> info;
vector<pair<string, int>> temp;

void dfs(string order, string str, int idx, int level)
{
    if(str.size() == level) {
        info[str]++;
        return;
    }
    for(int i = idx; i < order.size(); i++) {
        str[level] = order[i];
        dfs(order, str, i + 1, level + 1);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> ans;
    for(int i = 0; i < orders.size(); i++) {
        sort(orders[i].begin(), orders[i].end());
        for(int j = 0; j < course.size(); j++) {
            string str;
            str.resize(course[j]);
            dfs(orders[i], str, 0, 0);
        }
    }
    
    for(auto iter : info) {
        if(info[iter.first] >= 2) {
            temp.push_back({iter.first, iter.second});
        }
    }
    
    for(int i = 0; i < course.size(); i++) {
        int x = -1;
        for(int j = 0; j < temp.size(); j++) {
            if(temp[j].first.size() == course[i]) {
                if(x < temp[j].second) {
                    x = max(x, temp[j].second);
                }
            }
        }
        
        for(int j = 0; j < temp.size(); j++) {
            if(temp[j].first.size() == course[i]) {
                if(x == temp[j].second) {
                    ans.push_back(temp[j].first);
                }
            }
        }
    }
    
    sort(ans.begin(), ans.end());
    return ans;
}