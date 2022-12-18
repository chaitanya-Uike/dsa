#include <bits/stdc++.h>

using namespace std;

int *findTwoElement(int *arr, int n)
{
    int *res = new int[2];
    for (int i = 0; i < n; i++)
    {
        if (arr[abs(arr[i]) - 1] < 0)
            res[0] = abs(arr[i]);
        else
            arr[abs(arr[i]) - 1] *= -1;
    }

    for (int i = 0; i < n; i++)
        if (arr[i] >= 0)
            res[1] = i + 1;
    return res;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int *res = findTwoElement(arr, n);

    cout << res[0] << " " << res[1];
    return 0;
}