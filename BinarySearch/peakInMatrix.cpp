#include <bits/stdc++.h>

using namespace std;
vector<int> findPeakGrid(vector<vector<int>> &mat)
{
    int r = mat.size();
    int c = mat[0].size();

    int start = 0;
    int end = c - 1;

    while (start < end)
    {
        int mid = start + (end - start) / 2;

        int l = 0;
        int h = r - 1;

        while (l < h)
        {
            int m = l + (h - l) / 2;
            if (mat[m][mid] > mat[m + 1][mid])
                h = m;
            else if (mat[m][mid] < mat[m + 1][mid])
                l = m + 1;
        }
        if (mid > 0 && mat[l][mid] > mat[l][mid + 1] && mat[l][mid] > mat[l][mid - 1])
            return vector<int>{l, mid};
        else if (mid == 0 && mat[l][mid] > mat[l][mid + 1])
            return vector<int>{l, 0};
        else if (mat[l][mid] > mat[l][mid + 1])
            end = mid;
        else if (mat[l][mid] < mat[l][mid + 1])
            start = mid + 1;
    }

    return vector<int>{r - 1, c - 1};
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];

    vector<int> res = findPeakGrid(matrix);

    cout << res[0] << " " << res[1];
    return 0;
}