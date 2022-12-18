#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<char, int> a, pair<char, int> b)
{
    return a.second > b.second;
}

string frequencySort(string s)
{
    vector<pair<char, int>> frq(80, {0, 0});

    for (auto c : s)
    {
        frq[c - '0'].first = c;
        frq[c - '0'].second++;
    }

    sort(frq.begin(), frq.end(), cmp);

    string res = "";

    for (auto i : frq)
    {
        while (i.second > 0)
        {
            res += i.first;
            i.second--;
        }
    }

    return res;
}

int main()
{
    string s;
    cin >> s;

    cout << frequencySort(s);

    return 0;
}