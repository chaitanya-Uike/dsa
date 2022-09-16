#include <bits/stdc++.h>

using namespace std;

void swap(vector<int> &v, int x, int y)
{
    int temp = v[x];
    v[x] = v[y];
    v[y] = temp;
}

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = 0, j = n - 1;
    int x, y;

    while (nums1[m - 1] > nums2[0])
    {
        while (nums1[i] < nums2[0] && i < m)
            i++;

        int temp = nums1[m - 1];
        nums1[m - 1] = nums2[0];
        nums2[0] = temp;

        x = m - 1;
        while (x > i)
        {
            swap(nums1, x, x - 1);
            x--;
        }
        y = 0;
        while (nums2[j] > nums2[0] && j >= 0)
            j--;
        y = 0;
        while (y < j)
        {
            swap(nums2, y, y + 1);
            y++;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v1(n), v2(m);

    for (int i = 0; i < n; i++)
        cin >> v1[i];
    for (int i = 0; i < m; i++)
        cin >> v2[i];

    merge(v1, n, v2, m);

    for (auto i : v1)
        cout << i << " ";
    for (auto i : v2)
        cout << i << " ";
    return 0;
}