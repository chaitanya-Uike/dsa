#include <bits/stdc++.h>

using namespace std;

int gcd(int x, int y)
{
    int A, B;
    if (x > y)
    {
        A = x;
        B = y;
    }
    else
    {
        B = x;
        A = y;
    }

    while (B != 0)
    {
        int r = A % B;
        A = B;
        B = r;
    }

    return A;
}

int main()
{
    cout << gcd(25, 150);
    return 0;
}