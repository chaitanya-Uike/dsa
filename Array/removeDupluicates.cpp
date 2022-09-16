#include <bits/stdc++.h>

using namespace std;

void swap(vector<int> &v, int x, int y)
{
    int temp = v[x];
    v[x] = v[y];
    v[y] = temp;
}

int removeDuplicates(vector<int> &nums)
{
    int i = 0;
    int j = 0;
    int curr;
    while (j < nums.size())
    {
        if (nums[j] == curr)
        {
            j++;
            continue;
        }
        curr = nums[j];
        swap(nums, i, j);
        i++;
        j++;
    }

    return i - 1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int m = removeDuplicates(v);
    for (int i = 0; i <= m; i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}