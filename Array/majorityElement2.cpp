// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

#include <bits/stdc++.h>

using namespace std;

vector<int> majorityElement(vector<int> &nums)
{
    int n1 = 0;
    int c1 = 0;
    int n2 = 0;
    int c2 = 0;

    int size = nums.size() / 3;

    for (auto i : nums)
    {
        if (n1 == i)
            c1++;
        else if (n2 == i)
            c2++;
        else if (c1 == 0)
        {
            n1 = i;
            c1 = 1;
        }
        else if (c2 == 0)
        {
            n2 = i;
            c2 = i;
        }
        else
        {
            c1--;
            c2--;
        }
    }
    c1 = 0;
    c2 = 0;
    for (auto i : nums)
    {
        if (i == n1)
            c1++;
        else if (i == n2)
            c2++;
    }
    vector<int> res;
    if (c1 > size)
        res.push_back(n1);
    if (c2 > size)
        res.push_back(n2);

    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i];

    vector<int> res = majorityElement(vec);
    for (auto i : res)
        cout << i << " ";

    return 0;
}