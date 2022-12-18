#include <bits/stdc++.h>

using namespace std;

vector<int> leaders(int a[], int n)
{
    vector<int> res;
    int max_ = INT_MIN;

    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] > max_)
        {
            res.push_back(a[i]);
            max_ = a[i];
        }
    }

    int i = 0, j = res.size() - 1;
    while (i < j)
    {
        int z = res[i];
        res[i] = res[j];
        res[j] = z;
        i++;
        j--;
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> res = leaders(a, n);

    for (auto i : res)
        cout << i << " ";
    return 0;
}