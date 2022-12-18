#include <bits/stdc++.h>

using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> rowHash(n, 0);
    vector<int> colHash(m, 0);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                rowHash[i] = 1;
                colHash[j] = 1;
            }
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (rowHash[i] == 1 || colHash[j] == 1)
                matrix[i][j] = 0;
        }
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    setZeroes(matrix);

    for (auto row : matrix)
    {
        for (auto col : row)
            cout << col << " ";
        cout << endl;
    }

    return 0;
}