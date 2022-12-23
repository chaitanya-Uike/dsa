#include <bits/stdc++.h>

using namespace std;

void f(vector<int> &nums, int target, vector<int> sub, int pos, vector<vector<int>> &res)
{
    if (pos == nums.size() + 1)
        return;

    if (target == 0)
    {
        res.push_back(sub);
        return;
    }

    if (nums[pos] <= target)
    {
        sub.push_back(nums[pos]);
        f(nums, target - nums[pos], sub, pos, res);
        sub.pop_back();
    }

    f(nums, target, sub, pos + 1, res);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> res;
    f(candidates, target, vector<int>(), 0, res);
    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<vector<int>> res = combinationSum(arr, k);

    for (auto i : res)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}