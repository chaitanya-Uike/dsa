#include <bits/stdc++.h>

using namespace std;

void f(vector<int> &arr, int n, int sum, vector<int> &res)
{
    if (n == -1)
    {
        res.push_back(sum);
        return;
    }

    f(arr, n - 1, sum + arr[n], res);
    f(arr, n - 1, sum, res);
}

vector<int> subsetSums(vector<int> arr, int N)
{
    vector<int> res;
    f(arr, N - 1, 0, res);
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> res = subsetSums(arr, n);

    for (auto i : res)
        cout << i << " ";

    return 0;
}