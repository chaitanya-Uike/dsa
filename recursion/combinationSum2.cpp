#include <bits/stdc++.h>

using namespace std;

void f(vector<int> &nums, int target, int pos, vector<int> sub, vector<vector<int>> &res)
{
    if (target == 0)
    {
        res.push_back(sub);
        return;
    }

    if (target < 0)
        return;

    int prevInserted = -1;
    for (int i = pos; i < nums.size(); i++)
    {
        if (prevInserted == nums[i])
            continue;
        sub.push_back(nums[i]);
        f(nums, target - nums[i], i + 1, sub, res);
        sub.pop_back();
        prevInserted = nums[i];
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<vector<int>> res;
    sort(candidates.begin(), candidates.end());
    f(candidates, target, 0, vector<int>(), res);

    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<vector<int>> res = combinationSum2(arr, k);

    for (auto i : res)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}