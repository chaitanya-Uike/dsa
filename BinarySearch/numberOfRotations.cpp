#include <bits/stdc++.h>

using namespace std;

int findKRotation(int arr[], int n)
{
    int l = 0;
    int h = n - 1;

    while (l < h)
    {
        int m = l + (h - l) / 2;
        if (arr[m] > arr[m + 1])
            return m + 1;
        else if (arr[m] < arr[n - 1])
            h = m;
        else if (arr[m] > arr[n - 1])
            l = m + 1;
    }

    return 0;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << findKRotation(arr, n);
    return 0;
}