#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &nums, int l, int h, int k)
{
    int n = nums.size();

    if (l == h)
    {
        if (nums[l] > 2 * k)
            return l;
        else
            return (l + (h - l) / 2) + 1;
    }

    while (l <= h)
    {
        int m = l + (h - l) / 2;
        if (m > 0 && nums[m] > 2LL * k && nums[m - 1] > 2LL * k)
            h = m - 1;
        else if (m < n - 1 && nums[m] <= 2LL * k && nums[m + 1] <= 2LL * k)
            l = m + 1;
        else if (m > 0 && nums[m] > 2LL * k && nums[m - 1] <= 2LL * k)
            return m;
        else if (m < n - 1 && nums[m] <= 2LL * k && nums[m + 1] > 2LL * k)
            return m + 1;
        else if (m == 0)
            return 0;
        else
            return h + 1;
    }

    return (l + (h - l) / 2) + 1;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << nums.size() - binarySearch(nums, 0, nums.size() - 1, k);
    return 0;
}