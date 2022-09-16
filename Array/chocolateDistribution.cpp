#include <bits/stdc++.h>

using namespace std;

long long findMinDiff(vector<long long> a, long long n, long long m)
{
    long long min_ = INT_MAX;
    long long i = 0;
    long long j = m - 1;

    sort(a.begin(), a.end());

    while (j < n)
    {
        min_ = min(min_, (a[j] - a[i]));
        i++;
        j++;
    }

    return min_;
}

int main()
{
    long long n, m;
    cin >> n >> m;
    vector<long long> a;

    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        a.push_back(x);
    }

    cout << findMinDiff(a, n, m);
    return 0;
}