#include <bits/stdc++.h>

using namespace std;

int subsetXOR(vector<int> arr, int N, int K)
{
    return 0;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int cXor = 0;
    for (int i = 0; i < n; i++)
    {
        cXor ^= arr[i];
        cout << cXor << " ";
    }

    // cout << subsetXOR(arr, n, k);
    return 0;
}