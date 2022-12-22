#include <bits/stdc++.h>

using namespace std;

void recurse(int n, int p, string str, vector<string> &res)
{
    string left = str.substr(0, p + 1);
    string right = str.substr(p + 1, str.length());

    str = left + "()" + right;

    if (n == 1)
    {
        res.push_back(str);
        return;
    }

    for (int i = p + 1; i < str.length(); i++)
        recurse(n - 1, i, str, res);
}

vector<string> generateParenthesis(int n)
{

    vector<string> res;

    if (n == 1)
    {
        res.push_back("()");
        return res;
    };

    recurse(n - 1, 0, "()", res);
    recurse(n - 1, 1, "()", res);

    return res;
}

int main()
{
    int n;
    cin >> n;

    vector<string> res = generateParenthesis(n);

    for (auto i : res)
    {
        cout << i << endl;
    }

    return 0;
}