#include <bits/stdc++.h>

using namespace std;

int main()
{
    queue<vector<int, int>> q;
    q.push({1, 1});
    cout << q.front()[0] << " " << q.front()[1];
    return 0;
}