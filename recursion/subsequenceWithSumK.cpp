#include <bits/stdc++.h>

using namespace std;

void f(vector<int> &nums, int i, vector<int> sub, int sum, int k, vector<vector<int>> &res)
{
    if (i == nums.size())
    {
        if (sum == k)
            res.push_back(sub);
        return;
    }

    f(nums, i + 1, sub, sum, k, res);
    sub.push_back(nums[i]);
    f(nums, i + 1, sub, sum + nums[i], k, res);
}

vector<vector<int>> subsWithSumK(vector<int> &nums, int k)
{
    vector<vector<int>> res;

    f(nums, 0, vector<int>(), 0, k, res);

    return res;
}

bool f2(vector<int> &nums, int i, vector<int> sub, int sum, int k, vector<int> &res)
{
    if (sum == k)
    {
        res = sub;
        return true;
    }
    if (i == nums.size())
        return false;

    if (f2(nums, i + 1, sub, sum, k, res))
        return true;

    sub.push_back(nums[i]);
    return f2(nums, i + 1, sub, sum + nums[i], k, res);
}

vector<int> subsWithSumK2(vector<int> &nums, int k)
{
    vector<int> res;

    f2(nums, 0, vector<int>(), 0, k, res);

    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<vector<int>> res = subsWithSumK(nums, k);

    vector<int> res2 = subsWithSumK2(nums, k);

    for (auto i : res2)
        cout << i << " ";

    for (auto i : res)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
