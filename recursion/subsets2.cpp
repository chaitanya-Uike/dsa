#include <bits/stdc++.h>

using namespace std;

void f(vector<int> &nums, vector<int> sub, int pos, vector<vector<int>> &res)
{
    if (pos == nums.size() + 1)
        return;

    res.push_back(sub);
    int prevInserted = -11;
    for (int i = pos; i < nums.size(); i++)
    {
        if (nums[i] == prevInserted)
            continue;
        sub.push_back(nums[i]);
        f(nums, sub, i + 1, res);
        sub.pop_back();
        prevInserted = nums[i];
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> res;
    f(nums, vector<int>(), 0, res);
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<vector<int>> res = subsetsWithDup(arr);

    for (auto i : res)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}