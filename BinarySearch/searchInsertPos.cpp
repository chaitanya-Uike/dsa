#include <bits/stdc++.h>

using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int l = 0;
    int h = nums.size() - 1;

    while (l <= h)
    {
        int m = l + (h - l) / 2;
        if (nums[m] == target)
            return m;
        else if (nums[m] > target)
            h = m - 1;
        else
            l = m + 1;
    }

    return h + 1;
}

int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << searchInsert(nums, target);
    return 0;
}