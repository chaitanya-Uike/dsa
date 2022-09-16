#include <bits/stdc++.h>

using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
    vector<int> sums = {0};
    int cSUm = 0;

    for (auto i : nums)
    {
        cSUm += i;
        sums.push_back(cSUm);
    }

    int i = 0, j = 0;

    int min_ = INT_MAX;

    int n = sums.size();
    bool changed = false;

    while (j < n)
    {
        if (target <= sums[j] - sums[i])
        {
            while (target <= sums[j] - sums[i] && i < j)
            {
                min_ = min(min_, j - i);
                changed = true;
                i++;
            }
        }
        else
            j++;
    }

    if (!changed)
        return 0;

    return min_;
}

int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> nums(n, 0);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << minSubArrayLen(target, nums);
    return 0;
}