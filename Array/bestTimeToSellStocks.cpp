#include <bits/stdc++.h>

using namespace std;

int solve(int a[], int n)
{
    int curr_min = INT_MAX;
    int profit = 0;

    for (int i = 0; i < n; i++)
    {
        curr_min = min(curr_min, a[i]);
        profit = max(profit, a[i] - curr_min);
    }

    return profit;
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