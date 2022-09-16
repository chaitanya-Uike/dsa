#include <bits/stdc++.h>

using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int count = 0;
    int cPro = 1;
    int res = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        cPro *= nums[i];

        if (cPro == 1)
            count++;
        else
        {
            cPro = 1;
            count = 0;
        }
        res = max(res, count);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    cout << findMaxConsecutiveOnes(v);

    return 0;
}