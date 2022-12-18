#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int memo[102][1002];

public:
    Solution()
    {
        memset(memo, -1, sizeof(memo));
    }

    int knapsack(int wt[], int val[], int W, int n)
    {
        if (W == 0 || n == 0)
            return 0;

        if (memo[n][W] != -1)
            return memo[n][W];

        if (wt[n - 1] <= W)
            return memo[n][W] = max(val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1), knapsack(wt, val, W, n - 1));

        return memo[n][W] = knapsack(wt, val, W, n - 1);
    }

    int knapsackTabulated(int wt[], int val[], int W, int n)
    {
        int T[n + 1][W + 1];

        for (int i = 0; i <= W; i++)
            T[0][i] = 0;
        for (int i = 0; i <= n; i++)
            T[i][0] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= W; j++)
            {
                if (wt[i - 1] <= j)
                    T[i][j] = max(val[i - 1] + T[i - 1][j - wt[i - 1]], T[i - 1][j]);
                else
                    T[i][j] = T[i - 1][j];
            }
        }

        return T[n][W];
    }
};

int main()
{
    int n, W;
    cin >> n >> W;
    int wt[n], val[n];

    for (int i = 0; i < n; i++)
        cin >> wt[i];

    for (int i = 0; i < n; i++)
        cin >> val[i];

    Solution s;

    cout << s.knapsack(wt, val, W, n) << endl;
    cout << s.knapsackTabulated(wt, val, W, n);

    return 0;
}