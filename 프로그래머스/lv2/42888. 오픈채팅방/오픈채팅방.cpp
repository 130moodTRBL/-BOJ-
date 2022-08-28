#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> ans;
    map<string, string> info;
    vector<vector<string>> arr;
    
    string order, id, name;
    for(int i = 0; i < record.size(); i++) {
        stringstream ss(record[i]);
        ss.str(record[i]);
        
        string s[3];
        string word;
        int pos = 0;
        vector<string> temp;
        while(ss >> word) 
        {
            s[pos++] = word;
        }
        temp.push_back(s[0]);
        temp.push_back(s[1]);
        temp.push_back(s[2]);
        arr.push_back(temp);
        
        if(s[0] == "Enter" || s[0] == "Change") {
            info[s[1]]= s[2];
        }
    }
    
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i][0] == "Enter") {
            ans.push_back(info[arr[i][1]] + "님이 들어왔습니다.");
        }
        else if(arr[i][0] == "Leave") {
            ans.push_back(info[arr[i][1]] + "님이 나갔습니다.");
        }
    }
    return ans;
}