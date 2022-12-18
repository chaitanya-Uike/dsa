#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<int>> res;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int t = target - nums[i] - nums[j];
            int l = j + 1;
            int h = n - 1;

            while (l < h)
            {
                if (t == nums[l] + nums[h])
                {
                    vector<int> quad = {nums[i], nums[j], nums[l], nums[h]};
                    res.push_back(quad);
                    int prev = nums[l];
                    while (nums[l] == prev && l < h)
                        l++;
                    prev = nums[h];
                    while (nums[h] == prev && h > l)
                        h--;
                }
                else if (t > nums[l] + nums[h])
                    l++;
                else
                    h--;
            }

            while (j + 1 < n && nums[j + 1] == nums[j])
                ++j;
        }
        while (i + 1 < n && nums[i + 1] == nums[i])
            ++i;
    }

    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<vector<int>> res = fourSum(nums, k);

    for (auto i : res)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}