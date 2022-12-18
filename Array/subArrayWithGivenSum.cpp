#include <bits/stdc++.h>

using namespace std;

vector<int> subArrayWithGivenSum(vector<int> &arr, int n, int k)
{
    int j = 0;
    int cSum = 0;
    vector<int> preSum(n + 1, 0);
    vector<int> res(2, -1);

    for (int i = 0; i < n; i++)
    {
        cSum += arr[i];
        preSum[i + 1] = cSum;
        if (cSum >= k)
        {
            while (j < i)
            {
                if (cSum - preSum[j] == k)
                {
                    res[0] = j;
                    res[1] = i;
                    return res;
                }
                j++;
            }
        }
    }
    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> res = subArrayWithGivenSum(arr, n, k);
    cout << res[0] << " " << res[1];

    return 0;
}