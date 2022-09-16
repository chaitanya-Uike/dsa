#include <bits/stdc++.h>

using namespace std;

double myPow(double x, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
    {
        double temp = myPow(x, n / 2);
        return temp * temp;
    }
    return myPow(x, n - 1) * x;
}

int main()
{
    double x;
    int n;
    cin >> x >> n;
    cout << myPow(x, n);
    return 0;
}