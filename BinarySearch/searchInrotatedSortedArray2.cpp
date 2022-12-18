#include <bits/stdc++.h>

using namespace std;

bool search(vector<int> &nums, int target)
{
    int n = nums.size();
    int l = 0;
    int h = n - 1;

    while (l <= h)
    {
        int m = l + (h - l) / 2;

        if (nums[l] == nums[m] && nums[l] == nums[h])
        {
            if (nums[l] == target)
                return true;
            l++;
            if (nums[h] == target)
                return true;
            h--;

            continue;
        }

        if (target == nums[m])
            return true;
        // m in left half but answer in right half
        if (target <= nums[h] && nums[m] > nums[h])
            l = m + 1;
        // m in right half ut answer in left half
        else if (target > nums[h] && nums[m] <= nums[h])
            h = m - 1;
        else if (target < nums[m])
            h = m - 1;
        else
            l = m + 1;
    }
    return false;
}

int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << search(nums, target);
    return 0;
}