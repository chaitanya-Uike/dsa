#include <bits/stdc++.h>

using namespace std;

void merge(int a[], int l, int h, int m)
{
    vector<int> temp;
    int i = l, j = m + 1;

    while (i <= m && j <= h)
    {
        if (a[i] < a[j])
            temp.push_back(a[i++]);
        else
        {
            temp.push_back(a[j++]);
            cout << m - i + 1 << endl;
        }
    }

    while (i <= m)
        temp.push_back(a[i++]);
    while (j <= h)
        temp.push_back(a[j++]);

    int k = 0;
    for (int i = l; i <= h; i++)
        a[i] = temp[k++];
}

void mergeSort(int a[], int l, int h)
{
    if (l >= h)
        return;

    int m = (l + h) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, h);
    merge(a, l, h, m);
}

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    mergeSort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}