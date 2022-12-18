#include <bits/stdc++.h>

using namespace std;

void merge(long long arr[], long long l, long long m, long long h, long long int &count)
{
    int i = l;
    int j = m + 1;
    int k = 0;
    int temp[h - l + 1];

    while (i <= m && j <= h)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
        {
            temp[k++] = arr[j++];
            count += m - i + 1;
        }
    }

    while (i <= m)
        temp[k++] = arr[i++];
    while (j <= h)
        temp[k++] = arr[j++];

    k = 0;
    while (l <= h)
        arr[l++] = temp[k++];
}

void mergeSort(long long arr[], long long l, long long h, long long int &count)
{
    if (l < h)
    {
        long long m = l + (h - l) / 2;
        mergeSort(arr, l, m, count);
        mergeSort(arr, m + 1, h, count);
        merge(arr, l, m, h, count);
    }
}

long long int inversionCount(long long arr[], long long N)
{
    long long int count = 0;
    mergeSort(arr, 0, N - 1, count);
    return count;
}

int main()
{
    long long n;
    cin >> n;
    long long arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << inversionCount(arr, n);
    return 0;
}