#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &nums, int x, int l, int h)
{
    if (l > h)
        return -1;

    int m = l + (h - l) / 2;

    if (nums[m] == x)
        return m;
    else if (nums[m] > x)
        return binarySearch(nums, x, l, m - 1);
    return binarySearch(nums, x, m + 1, h);
}

int binarySearchIter(vector<int> &nums, int x)
{
    int l = 0;
    int h = nums.size() - 1;

    while (l <= h)
    {
        int m = l + (h - l) / 2;
        if (nums[m] == x)
            return m;
        else if (nums[m] > x)
            h = m - 1;
        else
            l = m + 1;
    }

    return -1;
}

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << binarySearch(nums, x, 0, n - 1) << " " << binarySearchIter(nums, x);
    return 0;
}