#include <bits/stdc++.h>

using namespace std;

long long int substrCount(string s, int k)
{
    map<char, int> hashMap;
    map<char, int>::iterator it;

    int i = 0, j = 0;
    int count = 0;

    while (j < s.length())
    {
        it = hashMap.find(s[j]);
        if (it == hashMap.end())
            hashMap.insert(pair<char, int>(s[j], 1));
        else
            it->second++;

        if (hashMap.size() == k)
            count++;

        if (hashMap.size() >= k)
        {
        }

        j++;
    }

    return count;
}

int main()
{
    int k;
    string s;
    cin >> s >> k;

    cout << substrCount(s, k);
    return 0;
}