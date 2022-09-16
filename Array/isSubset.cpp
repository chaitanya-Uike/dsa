// Array Subset of another array

#include <bits/stdc++.h>

using namespace std;

// tine complexity O(nLogn)
string isSubset(int a1[], int a2[], int n, int m)
{
    sort(a1, a1 + n);
    sort(a2, a2 + m);
    int i, j = 0;

    for (i = 0; i < n; i++)
    {
        if (a1[i] == a2[j])
        {
            j++;

            if (j == m)
                return "Yes";
        }
    }

    return "No";
}

// tine complexity O(n) and space complexity O(n)
string isSubset2(int a1[], int a2[], int n, int m)
{
    unordered_map<int, int> hash_map;
    unordered_map<int, int>::iterator it;
    for (int i = 0; i < n; i++)
    {
        it = hash_map.find(a1[i]);
        if (it == hash_map.end())
            hash_map.insert(pair<int, int>(a1[i], 1));
        else
            it->second++;
    }

    for (int i = 0; i < m; i++)
    {
        it = hash_map.find(a2[i]);
        if (it == hash_map.end() || it->second == 0)
            return "No";

        it->second--;
    }

    return "Yes";
}

int main()
{

    return 0;
}