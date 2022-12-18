#include <bits/stdc++.h>

using namespace std;

vector<int> maxMeetings(int start[], int end[], int n)
{
    vector<vector<int>> v;

    for (int i = 0; i < n; i++)
    {
        vector<int> meet = {end[i], start[i], i + 1};
        v.push_back(meet);
    }

    sort(v.begin(), v.end());

    vector<int> res;

    int prevMeetingEnd = -1;

    for (auto it : v)
    {
        if (it[1] > prevMeetingEnd)
        {
            res.push_back(it[2]);
            prevMeetingEnd = it[0];
        }
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    int start[n];
    int end[n];

    for (int i = 0; i < n; i++)
    {
        cin >> start[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> end[i];
    }

    vector<int> res = maxMeetings(start, end, n);

    for (auto it : res)
        cout << it << " ";

    return 0;
}