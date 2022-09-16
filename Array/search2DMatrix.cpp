#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &v, int target)
{
    int l = 0;
    int h = v.size() - 1;

    while (l <= h)
    {
        int m = l + (h - l) / 2;
        if (v[m] == target)
            return m;
        if (v[m] > target)
            h = m - 1;
        else
            l = m + 1;
    }

    return -1;
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int index;
    for (auto row : matrix)
    {
        if (row[0] <= target && row[row.size() - 1] >= target)
        {
            index = binarySearch(row, target);
            break;
        }
    }

    if (index < 0)
        return false;
    return true;
}

int main()
{

    return 0;
}