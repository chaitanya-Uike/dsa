#include <bits/stdc++.h>

using namespace std;

int findPlatform(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);

    int i = 0, j = 0;
    int count = 0;
    int res = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= dep[j])
        {
            count++;
            res = max(res, count);
        }
        else
        {
            j++;
        }
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    int arr[n], dep[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> dep[i];
    }

    cout << findPlatform(arr, dep, n);

    return 0;
}