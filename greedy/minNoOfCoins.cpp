#include <bits/stdc++.h>

using namespace std;

int minCoins(int coins[], int m, int V)
{
    int coinsReq = 0;
    int max_ = 0;
    for (int i = 1; i < m; i++)
    {
        if (coins[i] <= V)
            max_ = i;
        else
            break;
    }
    cout << coins[max_] << endl;

    return coinsReq;
}

int main()
{
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int m = 9;
    int V;
    cin >> V;
    cout << minCoins(coins, m, V);
    return 0;
}