#include <bits/stdc++.h>

using namespace std;

string rotate(string s)
{
    int n = s.length();
    char temp = s[0];

    for (int i = 1; i < n; i++)
    {
        s[i - 1] = s[i];
    }

    s[n - 1] = temp;

    return s;
}

bool rotateString(string s, string goal)
{
    if (s.length() != goal.length())
        return false;

    for (int i = 0; i < s.length(); i++)
    {
        if (s == goal)
            return true;
        s = rotate(s);
    }

    return false;
}

int main()
{
    string s, goal;
    cin >> s >> goal;

    cout << rotateString(s, goal);
    return 0;
}