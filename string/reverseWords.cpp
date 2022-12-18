#include <bits/stdc++.h>

using namespace std;

string reverseWords(string s)
{
    string res = "";

    string token = "";

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            if (res.length() > 0 && token.length() > 0)
                res = token + " " + res;
            else if (token.length() > 0)
                res = token;
            token = "";
        }
        else
            token += s[i];
    }

    if (res.length() > 0 && token.length() > 0)
        return token + " " + res;
    if (token.length() > 0)
        return token + res;
    return res;
}
int main()
{
    string s;
    getline(cin, s);
    cout << reverseWords(s);
    return 0;
}