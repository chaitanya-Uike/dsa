#include <bits/stdc++.h>

using namespace std;

vector<int> rearrangeArray(vector<int> &arr)
{
    int n = arr.size();
    vector<int> res(n);
    int i = 0;
    int j = 1;

    for (auto it : arr)
    {
        if (it >= 0)
        {
            res[i] = it;
            i += 2;
        }
        else
        {
            res[j] = it;
            j += 2;
        }
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    arr = rearrangeArray(arr);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}