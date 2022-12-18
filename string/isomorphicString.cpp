#include <bits/stdc++.h>

using namespace std;

bool isIsomorphic(string s, string t)
{
    if (s.length() != t.length())
        return false;

    map<char, char> map1;
    map<char, char> map2;

    for (int i = 0; i < s.length(); i++)
    {
        if (map1.find(s[i]) == map1.end() && map2.find(t[i]) == map2.end())
        {
            map1.insert(pair<char, char>(s[i], t[i]));
            map2.insert(pair<char, char>(t[i], s[i]));
        }
        else if (map1.find(s[i])->second != t[i] || map2.find(t[i])->second != s[i])
            return false;
    }
    return true;
}

int main()
{
    string t, s;
    cin >> s >> t;
    cout << isIsomorphic(s, t);
    return 0;
}