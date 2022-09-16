// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

#include <bits/stdc++.h>

using namespace std;

vector<int> majorityElement(vector<int> &nums)
{
    unordered_map<int, int> candidates = {{0, 0}, {1, 0}};
    unordered_map<int, int>::iterator it;
    int size = nums.size() / 3;
    vector<int> res;
    int min_;
    int minNum;
    set<int> s;

    for (auto i : nums)
    {
        it = candidates.find(i);
        if (it != candidates.end())
        {
            it->second++;
            if (it->second > size)
                s.insert(it->first);
        }
        else
        {
            min_ = INT_MAX;
            for (auto j : candidates)
            {
                if (min_ < j.second)
                {
                    min_ = j.second;
                    minNum = j.first;
                }
            }
            candidates.erase(minNum);
            candidates.insert(pair<int, int>(i, 1));
            if (size == 0)
                s.insert(i);
        }
    }

    for (auto i : s)
        res.push_back(i);

    return res;
}

int main()
{
    int n, x;
    cin >> n;
    vector<int> vec;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        vec.push_back(x);
    }

    vector<int> res = majorityElement(vec);
    for (auto i : res)
        cout << i << " ";

    return 0;
}