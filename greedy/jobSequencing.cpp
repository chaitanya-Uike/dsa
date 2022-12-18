#include <bits/stdc++.h>

using namespace std;

struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline

    void insert(int id, int dead, int profit)
    {
        this->profit = profit;
        this->dead = dead;
        this->id = id;
    }
};

bool comparator(Job a, Job b)
{
    return (a.profit > b.profit);
}

vector<int> JobScheduling(Job arr[], int n)
{
    sort(arr, arr + n, comparator);

    int maxDead = arr[0].dead;

    for (int i = 1; i < n; i++)
    {
        maxDead = max(maxDead, arr[i].dead);
    }

    int slots[maxDead + 1];

    for (int i = 0; i <= maxDead; i++)
        slots[i] = -1;

    int profit = 0;
    int jobsDone = 0;
    vector<int> res;

    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].dead; j >= 0; j--)
        {
            if (slots[j] == -1)
            {
                profit += arr[i].profit;
                slots[j] = arr[i].id;
                jobsDone++;
                break;
            }
        }
    }

    res.push_back(jobsDone);
    res.push_back(profit);

    return res;
}

int main()
{
    Job j1, j2, j3, j4;
    j1.insert(1, 4, 20);
    j2.insert(2, 1, 10);
    j3.insert(3, 1, 40);
    j4.insert(4, 1, 30);
    Job arr[] = {j1, j2, j3, j4};
    vector<int> res = JobScheduling(arr, 4);

    cout << res[0] << " " << res[1];
    return 0;
}