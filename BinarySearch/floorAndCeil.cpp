#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x)
{
    int l = 0;
    int h = n - 1;
    pair<int, int> res = {-1, -1};

    sort(arr, arr + n);

    while (l <= h)
    {
        int m = l + (h - l) / 2;
        if (arr[m] == x)
        {
            res.first = arr[m];
            res.second = arr[m];
            return res;
        }
        else if (arr[m] > x)
            h = m - 1;
        else
            l = m + 1;
    }

    if (arr[h] < x)
        res.first = arr[h];
    if (arr[l] > x)
        res.second = arr[l];

    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    pair<int, int> res = getFloorAndCeil(arr, n, k);
    cout << res.first << " " << res.second;
    return 0;
}