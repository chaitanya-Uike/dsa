#include <bits/stdc++.h>

using namespace std;

int M = 1000000007;

int f(int arr[], int n, int sum, int currSum, vector<vector<int>> &memo)
{
    if (currSum > sum)
        return 0;
    if (n == -1)
    {
        if (currSum == sum)
            return 1;
        return 0;
    }

    if (memo[n][currSum] != -1)
        return memo[n][currSum];

    const int res = (f(arr, n - 1, sum, currSum + arr[n], memo) % M + f(arr, n - 1, sum, currSum, memo) % M) % M;

    memo[n][currSum] = res;

    return res;
}

int perfectSum(int arr[], int n, int sum)
{
    vector<vector<int>> memo(n, vector<int>(sum + 1, -1));
    return f(arr, n - 1, sum, 0, memo);
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << perfectSum(arr, n, k);

    return 0;
}