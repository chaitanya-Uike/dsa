#include <bits/stdc++.h>

using namespace std;

void swap(vector<int> &a, int x, int y)
{
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}

void threeWayPartition(vector<int> &array, int a, int b)
{
    int n = array.size();
    int i = 0, k = 0, j = n - 1;

    while (k < j)
    {
        if (array[k] < a)
        {
            swap(array, i, k);
            i++;
            if (k < i)
                k = i;
        }
        else if (array[k] > b)
        {
            swap(array, j, k);
            j--;
        }
        else
            k++;
    }
}

int main()
{
    int n, a, b;
    cin >> n;
    vector<int> array(n, 0);

    for (int i = 0; i < n; i++)
        cin >> array[i];

    cin >> a >> b;

    threeWayPartition(array, a, b);

    for (auto it : array)
        cout << it << " ";
    return 0;
}