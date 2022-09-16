#include <bits/stdc++.h>

using namespace std;

long long trappingWater(int arr[], int n)
{
    int maxLeft[n];
    int maxRight[n];

    int i = 0, j = n - 1;
    int maxL = INT_MIN, maxR = INT_MIN;

    while (i < n && j >= 0)
    {
        maxL = max(arr[i], maxL);
        maxR = max(arr[j], maxR);

        maxLeft[i++] = maxL;
        maxRight[j--] = maxR;
    }

    long long res = 0;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == maxLeft[i] || arr[i] == maxRight[i])
            continue;
        res += min(maxLeft[i], maxRight[i]) - arr[i];
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << trappingWater(arr, n);
    return 0;
}