#include <bits/stdc++.h>

using namespace std;

bool solve(int a[], int n)
{
    unordered_map<int, int> hash_map;
    int cSum = 0;

    for (int i = 0; i < n; i++)
    {
        cSum += a[i];
        if (cSum == 0)
            return true;

        if (hash_map.find(cSum) != hash_map.end())
            return true;

        hash_map.insert(pair<int, int>(cSum, i));
    }

    return false;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << solve(a, n);
    return 0;
}