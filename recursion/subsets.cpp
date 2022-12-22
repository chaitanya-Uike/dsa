#include <bits/stdc++.h>

using namespace std;

void recurse(vector<int> &nums, int i, vector<int> sub, vector<vector<int>> &res)
{
    if (i == nums.size())
    {
        res.push_back(sub);
        return;
    }

    vector<int> include = sub;
    include.push_back(nums[i]);

    recurse(nums, i + 1, sub, res);
    recurse(nums, i + 1, include, res);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> res;
    recurse(nums, 0, vector<int>(), res);
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<vector<int>> res = subsets(nums);

    for (auto i : res)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}