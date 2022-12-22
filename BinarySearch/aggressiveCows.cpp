#include <bits/stdc++.h>

using namespace std;

bool check(vector<int> &stalls, int k, int minDist)
{
    int prevPos = stalls[0];
    k--;
    int i = 1;
    while (i < stalls.size() && k > 0)
    {
        if (stalls[i] - prevPos >= minDist)
        {
            k--;
            prevPos = stalls[i];
        }
        i++;
    }

    if (k == 0)
        return true;
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int l = 1;
    int h = stalls[stalls.size() - 1] - 1;
    int m;
    int latestPossible = 1;

    while (l <= h)
    {
        m = l + (h - l) / 2;

        if (check(stalls, k, m))
        {
            latestPossible = m;
            l = m + 1;
        }
        else
            h = m - 1;
    }

    return latestPossible;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> stalls(n);

    for (int i = 0; i < n; i++)
        cin >> stalls[i];

    cout << aggressiveCows(stalls, k);
    return 0;
}