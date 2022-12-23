#include <bits/stdc++.h>

using namespace std;

void f(int k, int n, vector<int> sub, int i, vector<vector<int>> &res)
{
    if (sub.size() == k)
    {
        if (n == 0)
            res.push_back(sub);
        return;
    }

    for (i; i <= 9; i++)
    {
        if (n - i < 0)
            return;
        sub.push_back(i);
        f(k, n - i, sub, i + 1, res);
        sub.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> res;
    f(k, n, vector<int>(), 1, res);
    return res;
}

int main()
{
    int k, n;
    cin >> k >> n;

    vector<vector<int>> res = combinationSum3(k, n);

    for (auto i : res)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}