#include <bits/stdc++.h>

using namespace std;

int oneStartsAt(vector<int> &arr)
{
    int n = arr.size();
    int l = 0;
    int h = n - 1;

    while (l <= h)
    {
        int m = (l + h) / 2;
        if (arr[m] == 1 && m == 0)
            return n;
        else if (arr[m] == 0 && m == n - 1)
            return 0;
        else if (arr[m] == 1 && m - 1 >= 0 && arr[m - 1] == 1)
            h = m - 1;
        else if (arr[m] == 0 && m + 1 < n && arr[m + 1] == 0)
            l = m + 1;
        else if (arr[m] == 0 && m + 1 < n && arr[m + 1] == 1)
            return n - m - 1;
        else
            return n - m;
    }

    return -1;
}

int rowWithMax1s(vector<vector<int>> arr, int n, int m)
{
    int max_ = INT_MIN;
    int res;
    for (int i = 0; i < n; i++)
    {
        int len = oneStartsAt(arr[i]);
        if (max_ < len)
        {
            res = i;
            max_ = len;
        }
    }
    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    cout << rowWithMax1s(arr, n, m);

    return 0;
}