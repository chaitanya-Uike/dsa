#include <bits/stdc++.h>

using namespace std;

int kadanes(int a[], int n)
{
    int maxSum = INT_MIN;
    int cSum = 0;

    for (int i = 0; i < n; i++)
    {
        cSum += a[i];
        maxSum = max(maxSum, cSum);

        if (cSum < 0)
            cSum = 0;
    }

    return maxSum;
}

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << kadanes(a, n);
    return 0;
}