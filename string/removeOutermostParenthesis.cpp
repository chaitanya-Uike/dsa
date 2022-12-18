#include <bits/stdc++.h>

using namespace std;

string removeOuterParentheses(string s)
{
    stack<char> stack;
    string res = "";
    string curr = "";
    for (int i = 0; i < s.length(); i++)
    {
        curr += s[i];
        if (s[i] == '(')
            stack.push(s[i]);
        else
        {
            stack.pop();
            if (stack.empty())
            {
                res += curr.substr(1, curr.length() - 2);
                curr = "";
            }
        }
    }

    return res;
}

int main()
{
    string s;
    cin >> s;
    cout << removeOuterParentheses(s);
    return 0;
}