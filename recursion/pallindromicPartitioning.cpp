#include <bits/stdc++.h>

using namespace std;

bool isPallindrome(string s)
{
    int i = 0;
    int j = s.length() - 1;

    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

void f(string s, vector<string> sub, vector<vector<string>> &res)
{
    if (s.length() == 0)
        return res.push_back(sub);

    for (int i = 1; i <= s.length(); i++)
    {
        string left = s.substr(0, i);
        string right = s.substr(i);

        if (!isPallindrome(left))
            continue;

        sub.push_back(left);
        f(right, sub, res);
        sub.pop_back();
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> res;

    f(s, vector<string>(), res);

    return res;
}

int main()
{
    string s;
    cin >> s;

    vector<vector<string>> res = partition(s);

    for (auto i : res)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}