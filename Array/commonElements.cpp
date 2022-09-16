#include <bits/stdc++.h>

using namespace std;

void inputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    vector<int> result;
    int i, j, k;
    i = j = k = 0;

    int cMax = INT_MIN;
    int value;
    while (i < n1 && j < n2 && k < n3)
    {
        if (A[i] == B[j] && B[j] == C[k])
        {
            value = A[i];
            result.push_back(value);
            while (A[i] == value)
                i++;
            while (B[j] == value)
                j++;
            while (C[k] == value)
                k++;
        }

        cMax = max(A[i], max(B[j], C[k]));

        while (A[i] < cMax)
            ++i;
        while (B[j] < cMax)
            ++j;
        while (C[k] < cMax)
            ++k;
    }

    return result;
}

int main()
{
    int n1, n2, n3;
    cin >> n1;
    int A[n1];
    inputArray(A, n1);
    cin >> n2;
    int B[n2];
    inputArray(B, n2);
    cin >> n3;
    int C[n3];
    inputArray(C, n3);

    vector<int> result = commonElements(A, B, C, n1, n2, n3);

    for (auto it : result)
        cout << it << " ";

    return 0;
}