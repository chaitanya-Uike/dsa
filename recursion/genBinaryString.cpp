#include <bits/stdc++.h>

using namespace std;

void recurse(int n, string str)
{
    if (n == 0)
    {
        cout << str << " ";
        return;
    }

    recurse(n - 1, str + '0');
    if (str[str.length() - 1] != '1')
        recurse(n - 1, str + '1');
}

int main()
{
    int n;
    cin >> n;
    recurse(n, "");
    return 0;
}