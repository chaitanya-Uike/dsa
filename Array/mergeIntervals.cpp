#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> merged;

    sort(intervals.begin(), intervals.end());

    for (int i = 0; i < intervals.size(); i++)
    {
        if (merged.size() == 0 || merged[merged.size() - 1][1] < intervals[i][0])
        {
            merged.push_back(intervals[i]);
        }
        else
        {
            if (intervals[i][1] > merged[merged.size() - 1][1])
                merged[merged.size() - 1][1] = intervals[i][1];
        }
    }

    return merged;
}

int main()
{
    // {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> intervals = {{1, 4},
                                     {2, 3}};
    vector<vector<int>>
        merged = merge(intervals);

    for (auto interval : merged)
    {
        for (auto it : interval)
        {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}