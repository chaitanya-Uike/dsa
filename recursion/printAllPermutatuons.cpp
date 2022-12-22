#include <bits/stdc++.h>

using namespace std;

string removeChar(string str, int pos)
{
    string left = str.substr(0, pos);
    string right = str.substr(pos + 1);

    return left + right;
}

void f(string perm, string rem, set<string> &res)
{
    if (rem.length() == 0)
    {
        res.insert(perm);
        return;
    }

    for (int i = 0; i < rem.length(); i++)
    {
        f(perm + rem[i], removeChar(rem, i), res);
    }
}

set<string> genAllPerms(string str)
{
    set<string> res;
    f("", str, res);
    return res;
}

int main()
{
    string str;
    cin >> str;
    set<string> res = genAllPerms(str);

    for (auto i : res)
        cout << i << " ";
    return 0;
}