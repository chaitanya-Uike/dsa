#include <bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    if (s.size() == 0)
        return 0;

    int max_ = 1;
    int cLen = 0;
    unordered_map<char, int> hash_map;
    unordered_map<char, int>::iterator it;
    int lastNonRepeating = -1;

    for (int i = 0; i < s.size(); i++)
    {
        it = hash_map.find(s[i]);
        if (it == hash_map.end())
        {
            cLen++;
            hash_map.insert(pair<char, int>(s[i], i));
        }
        else
        {
            if (it->second > lastNonRepeating)
            {
                lastNonRepeating = it->second + 1;
                cLen = i - it->second;
                it->second = i;
            }
            else
                cLen++;
        }
        max_ = max(max_, cLen);
    }

    return max_;
}

int main()
{
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s);
    return 0;
}