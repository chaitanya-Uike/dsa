#include <bits/stdc++.h>

using namespace std;

int findLongestConseqSubseq(int arr[], int N)
{
    sort(arr, arr + N);
    int count = 1;
    int maxLen = 1;

    for (int i = 1; i < N; i++)
    {
        while (arr[i] == arr[i - 1])
            i++;
        if (arr[i] - arr[i - 1] == 1)

        {
            count++;
            maxLen = max(maxLen, count);
        }
        else
            count = 1;
    }

    return maxLen;
}

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << findLongestConseqSubseq(a, n);
    return 0;
}