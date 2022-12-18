#include <bits/stdc++.h>

using namespace std;

bool ispathAvailable(vector<vector<int>> &m, int n, int i, int j, string s, vector<string> &res, vector<vector<int>> mask)
{
    if (i < 0 || j >= n || i >= n || j < 0)
        return false;

    if (m[i][j] == 0)
        return false;

    if (i == n - 1 && j == n - 1)
    {
        res.push_back(s);
        return true;
    }

    if (mask[i][j] == 1)
        return false;

    mask[i][j] = 1;

    bool isPathAvail = false;
    // right
    if (ispathAvailable(m, n, i, j + 1, s + 'R', res, mask))
        isPathAvail = true;
    // down
    if (ispathAvailable(m, n, i + 1, j, s + 'D', res, mask))
        isPathAvail = true;
    // left
    if (ispathAvailable(m, n, i, j - 1, s + 'L', res, mask))
        isPathAvail = true;
    // UP
    if (ispathAvailable(m, n, i - 1, j, s + 'U', res, mask))
        isPathAvail = true;

    return isPathAvail;
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> res;
    vector<vector<int>> mask(n, vector<int>(n, 0));
    ispathAvailable(m, n, 0, 0, "", res, mask);
    return res;
}

int main()
{
    vector<vector<int>> m = {{1, 0, 0, 0},
                             {1, 1, 0, 1},
                             {1, 1, 0, 0},
                             {0, 1, 1, 1}};

    vector<string> res = findPath(m, 4);

    for (auto str : res)
        cout << str << endl;

    return 0;
}