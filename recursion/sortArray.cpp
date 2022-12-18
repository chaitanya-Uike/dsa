#include <bits/stdc++.h>

using namespace std;

void insert(vector<int> &arr, int x)
{
    if (arr.size() == 0 || arr[arr.size() - 1] < x)
    {
        arr.push_back(x);
        return;
    }

    int curr = arr[arr.size() - 1];
    arr.pop_back();
    insert(arr, x);
    arr.push_back(curr);
}

void sort(vector<int> &arr)
{
    if (arr.size() == 0 || arr.size() == 1)
        return;

    int curr = arr[arr.size() - 1];
    arr.pop_back();

    sort(arr);

    insert(arr, curr);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}