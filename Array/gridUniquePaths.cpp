#include <bits/stdc++.h>

using namespace std;

int getPaths(int m, int n, vector<vector<int>> &memo, int i, int j)
{
    if (i == m - 1 && j == n - 1)
        return 1;
    if (i >= m || j >= n)
        return 0;

    if (memo[i][j] != -1)
        return memo[i][j];

    int right = getPaths(m, n, memo, i, j + 1);
    int bottom = getPaths(m, n, memo, i + 1, j);

    memo[i][j + 1] = right;
    memo[i + 1][j] = bottom;

    return right + bottom;
}

int uniquePaths(int m, int n)
{
    vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));

    return getPaths(m, n, memo, 0, 0);
}

int main()
{
    int n, m;
    cin >> m >> n;

    cout << uniquePaths(m, n);
    return 0;
}