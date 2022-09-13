#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

vector<int> arr;
string ans;

string solution(string s) {
    stringstream ss(s);
    string str;
    while(ss >> str)
    {
        int n = stoi(str);
        arr.push_back(n);
    }
    sort(arr.begin(), arr.end());
    ans += to_string(arr[0]);
    ans = ans + " " + to_string(arr[arr.size() - 1]);
    
    return ans;
}