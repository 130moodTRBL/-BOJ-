#include <string>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

bool solution(string s)
{
    stack<int> stk;
    
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            stk.push(s[i]);
        }
        else if(s[i] == ')' && !stk.empty()) {
            stk.pop();
        }
    }
    if(s[0] == ')') {
        return false;
    }
    if(stk.empty()) {
        return true;
    }
    else {
        return false;
    }
}