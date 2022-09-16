#include <bits/stdc++.h>

using namespace std;

int solve(int a[], int n, int k)
{
    unordered_map<int, int> hash_map;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        unordered_map<int, int>::iterator it;

        it = hash_map.find(k - a[i]);
        if (it != hash_map.end())
        {
            count += it->second;
        }

        it = hash_map.find(a[i]);
        if (it == hash_map.end())
            hash_map.insert(pair(a[i], 1));
        else
            it->second++;
    }

    return count;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << solve(a, n, k);
    return 0;
}