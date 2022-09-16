#include <bits/stdc++.h>

using namespace std;

int longestConsecutive1(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;

    sort(nums.begin(), nums.end());

    int max_ = 1;
    int count = 1;
    int prev = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] - prev == 1)
            count++;
        else if (nums[i] != prev)
            count = 1;
        prev = nums[i];
        max_ = max(max_, count);
    }

    return max_;
}

int longestConsecutive(vector<int> &nums)
{
    if (nums.size() == 0)
        return 1;

    set<int> hash_map;
    for (auto num : nums)
        hash_map.insert(num);

    int max_ = 1;

    for (auto num : nums)
    {
        if (hash_map.find(num - 1) == hash_map.end())
        {
            int count = 1;
            int cNum = num;
            while (hash_map.find(cNum + 1) != hash_map.end())
            {
                cNum++;
                count++;
            }

            max_ = max(max_, count);
        }
    }

    return max_;
}

int main()
{
    int n, x;
    cin >> n;
    vector<int> nums;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        nums.push_back(x);
    }

    cout << longestConsecutive(nums);
    return 0;
}