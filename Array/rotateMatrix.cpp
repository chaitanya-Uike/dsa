#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> rotate(vector<vector<int>> &matrix)
{
    vector<vector<int>> res;
    for (int i = 0; i < matrix[0].size(); i++)
    {
        vector<int> newRow;
        for (int j = matrix.size() - 1; j >= 0; j--)
        {
            newRow.push_back(matrix[j][i]);
        }

        res.push_back(newRow);
    }

    return res;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    vector<vector<int>> res = rotate(matrix);

    for (auto row : res)
    {
        for (auto col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }

    return 0;
}