#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> findTriplets(vector<int> arr, int n, int K)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> res;
    int i = 0;
    while (i < n)
    {
        vector<int> triplet = {arr[i]};
        int p = i + 1;
        int q = n - 1;
        int reqSum = K - arr[i];

        while (p < q)
        {
            if (arr[p] + arr[q] == reqSum)
            {
                triplet.push_back(arr[p]);
                triplet.push_back(arr[q]);
                res.push_back(triplet);

                int temp1 = arr[p];
                int temp2 = arr[q];

                while (arr[p] == temp1)
                    p++;
                while (arr[q] == temp2)
                    q--;
            }
            if (arr[p] + arr[q] > reqSum)
                q--;
            else
                p++;
        }

        int prev = arr[i];
        while (prev == arr[i])
            i++;
    }

    return res;
}

int main()
{
    int n, k;
    cin >> n;
    vector<int> arr;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    cin >> k;

    vector<vector<int>> res = findTriplets(arr, n, k);

    for (auto triplet : res)
    {
        for (auto it : triplet)
        {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}