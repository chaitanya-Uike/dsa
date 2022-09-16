#include <bits/stdc++.h>

using namespace std;

int maxProduct(int a[], int n)
{
    int minPro = 1;
    int maxPro = 1;
    int temp;
    int res = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        temp = minPro;
        minPro = min(minPro * a[i], min(maxPro * a[i], a[i]));
        maxPro = max(maxPro * a[i], max(temp * a[i], a[i]));

        res = max(res, maxPro);

        if (maxPro == 0)
            maxPro = 1;
        if (minPro == 0)
            minPro = 1;
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << maxProduct(a, n);
    return 0;
}