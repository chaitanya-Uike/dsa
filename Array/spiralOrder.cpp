#include <bits/stdc++.h>

using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    cout << m << endl;

    vector<int> res;

    for (int j = 0; j <= n / 2; j++)
    {
        for (int i = j; i < m - j; i++)
        {
            if (res.size() == n * m)
                return res;
            res.push_back(matrix[j][i]);
        }
        for (int i = j + 1; i < n - j; i++)
        {
            if (res.size() == n * m)
                return res;
            res.push_back(matrix[i][m - 1 - j]);
        }
        for (int i = m - 2 - j; i >= j; i--)
        {
            if (res.size() == n * m)
                return res;
            res.push_back(matrix[n - 1 - j][i]);
        }
        for (int i = n - 2 - j; i >= 1 + j; i--)
        {
            if (res.size() == n * m)
                return res;
            res.push_back(matrix[i][j]);
        }
    }

    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];

    vector<int> res = spiralOrder(matrix);

    for (auto i : res)
        cout << i << " ";

    return 0;
}