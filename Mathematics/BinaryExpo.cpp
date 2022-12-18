#include <bits/stdc++.h>

using namespace std;

int pow(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;

    int temp;
    if (b % 2 == 0)
    {
        temp = pow(a, b / 2);
        return temp * temp;
    }

    temp = pow(a, (b - 1) / 2);
    return temp * temp * a;
}

int main()
{
    cout << pow(2, 4);
    return 0;
}