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
    int index = -1;

    int l = 0;
    int h = matrix.size() - 1;
    int col = matrix[0].size();

    while (l <= h)
    {
        int m = l + (h - l) / 2;

        if (matrix[m][0] <= target && matrix[m][col - 1] >= target)
        {
            index = binarySearch(matrix[m], target);
            break;
        }
        else if (matrix[m][0] > target)
            h = m - 1;
        else
            l = m + 1;
    }

    if (index < 0)
        return false;
    return true;
}

int main()
{
    int n, m, target;
    cin >> n >> m >> target;

    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];

    cout << searchMatrix(matrix, target);

    return 0;
}