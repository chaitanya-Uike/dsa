#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &nums, int l, int h, int k)
{
    int n = nums.size();
    long long prod = 2LL * k;

    
}

int merge(vector<int> &nums, int l, int m, int h)
{
    int i = l;
    int j = m + 1;
    vector<int> temp;
    int count = 0;

    while (i <= m && j <= h)
    {
        if (nums[i] < nums[j])
            temp.push_back(nums[i++]);
        else
        {
            int k = binarySearch(nums, i, m, nums[j]);
            count += m - k + 1;
            temp.push_back(nums[j++]);
        }
    }

    while (i <= m)
        temp.push_back(nums[i++]);
    while (j <= h)
        temp.push_back(nums[j++]);

    i = 0;
    while (l <= h)
        nums[l++] = temp[i++];

    return count;
}

int mergeSort(vector<int> &nums, int l, int h)
{
    int count = 0;

    if (l < h)
    {
        int m = l + (h - l) / 2;
        count += mergeSort(nums, l, m);
        count += mergeSort(nums, m + 1, h);
        count += merge(nums, l, m, h);
    }
    return count;
}

int reversePairs(vector<int> &nums)
{
    return mergeSort(nums, 0, nums.size() - 1);
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << reversePairs(nums);
    return 0;
}