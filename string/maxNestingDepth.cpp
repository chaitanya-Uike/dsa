#include <bits/stdc++.h>

using namespace std;

int maxDepth(string s)
{
    int ans = 0;
    int lvl = 0;
    for (auto c : s)
    {
        if (c == '(')
        {
            lvl++;
            ans = max(lvl, ans);
        }
        else if (c == ')')
            lvl--;
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;

    cout << maxDepth(s);
    return 0;
}