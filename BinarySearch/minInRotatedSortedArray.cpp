#include <bits/stdc++.h>

using namespace std;

int findMin(vector<int> &nums)
{
    int n = nums.size();
    int l = 0;
    int h = n - 1;

    while (l < h)
    {
        int m = l + (h - l) / 2;
        if (nums[m] > nums[n - 1])
            l = m + 1;
        else
            h = m;
    }

    return nums[l];
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << findMin(nums);
    return 0;
}