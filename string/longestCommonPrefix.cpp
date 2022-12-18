#include <bits/stdc++.h>

using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    string res = "";
    int l = INT_MAX;

    if (strs.size() == 1)
        return strs[0];

    for (int i = 1; i < strs.size(); i++)
    {
        int p = 0, q = 0;
        string curr = "";
        while (p < strs[0].length() && q < strs[i].length())
        {
            if (strs[0][p] == strs[i][q])
                curr += strs[0][p];
            else
                break;
            p++;
            q++;
        }
        if (curr.length() < l)
        {
            res = curr;
            l = curr.length();
        }
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<string> strs(n);

    for (int i = 0; i < n; i++)
    {
        cin >> strs[i];
    }

    cout << longestCommonPrefix(strs);
    return 0;
}