#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, string> x, pair<int, string> y)
{
    return x.first < y.first;
}

int main()
{
    int N;
    cin >> N;

    vector<pair<int, string>> v(N);

    for (int i = 0; i < N; i++)
        cin >> v[i].first >> v[i].second;

    stable_sort(v.begin(), v.end(), compare);

    for (int i = 0; i < N; i++)
        cout << v[i].first << " " << v[i].second << "\n";
}