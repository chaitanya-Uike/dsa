#include <bits/stdc++.h>

using namespace std;

string largestOddNumber(string num)
{
    string res = "";
    string curr = "";
    for (int i = 0; i < num.length(); i++)
    {
        curr += num[i];
        if ((num[i] - '0') % 2 == 1)
        {
            if (curr.length() > res.length())
                res = curr;
        }
    }
    return res;
}

int main()
{
    string s;
    cin >> s;
    cout << largestOddNumber(s);
    return 0;
}