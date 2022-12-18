#include <bits/stdc++.h>

using namespace std;

bool isAnagram(string s, string t)
{
    if (s.length() != t.length())
        return false;

    vector<int> freq(26, 0);

    for (int i = 0; i < s.length(); i++)
    {
        cout << s[i] - 'a' << endl;
        freq[s[i] - 'a']++;
    }
    for (int i = 0; i < t.length(); i++)
        freq[s[i] - 'a']--;

    return true;
}

int main()
{
    string s, t;
    cin >> s >> t;

    cout << isAnagram(s, t);
    return 0;
}