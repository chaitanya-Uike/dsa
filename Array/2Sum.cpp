#include <bits/stdc++.h>

using namespace std;

void solve(int a[], int n, int k)
{
    unordered_map<int, int> hash_map;

    for (int i = 0; i < n; i++)
    {
        unordered_map<int, int>::iterator it;
        it = hash_map.find(k - a[i]);

        if (it != hash_map.end())
            cout << a[i] << " " << it->first << endl;

        it = hash_map.find(a[i]);
        if (it == hash_map.end())
            hash_map.insert(pair<int, int>(a[i], i));
        else
            it->second = i;
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    solve(a, n, k);
    return 0;
}