#include <bits/stdc++.h>

using namespace std;

int LongestSubsetWithZeroSum(vector<int> arr)
{
    unordered_map<int, int> hash_map;
    int cSum = 0;
    int max_ = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        cSum += arr[i];
        if (cSum == 0)
            max_ = i + 1;
        else if (hash_map.find(cSum) != hash_map.end())
            max_ = max(max_, i - hash_map.find(cSum)->second);
        else
            hash_map.insert(pair<int, int>(cSum, i));
    }

    return max_;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << LongestSubsetWithZeroSum(arr);
    return 0;
}