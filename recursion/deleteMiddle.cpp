#include <bits/stdc++.h>

using namespace std;

void deleteMiddle(stack<int> &s, int n) 
{
    if (n == 0)
        return;
    if (n % 2 == 0 && s.size() == n / 2 || n % 2 == 1 && s.size() == n / 2 + 1)
    {
        s.pop();
        return;
    }

    int top = s.top();
    s.pop();
    deleteMiddle(s, n);
    s.push(top);
}

int main()
{
    int n;
    cin >> n;
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.push(x);
    }

    deleteMiddle(s, s.size());

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}