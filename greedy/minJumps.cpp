#include <bits/stdc++.h>

using namespace std;

int jump(vector<int> &nums)
{
    vector<int> dist;

    int target = nums.size() - 1;
    for (int i = 0; i <= target; i++)
        dist.push_back(target - i - nums[i]);

    int jumps = 0;
    int remDist = dist[0];
    int pos = 0;

    int low;
    int high;
    int min_;
    int minPos;

    while (remDist > 0)
    {
        jumps++;
        if (pos + 1 < high)
            low = high + 1;
        else
            low = pos + 1;
        high = pos + nums[pos];
        min_ = dist[low];
        minPos = low;
        for (int i = low + 1; i <= high && i < nums.size(); i++)
        {
            if (min_ >= dist[i])
            {
                min_ = dist[i];
                minPos = i;
            }
        }

        pos = minPos;
        remDist = min_;
    }

    if (nums[minPos] != 0 && minPos != target)
        jumps++;

    return jumps;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << jump(nums);
    return 0;
}