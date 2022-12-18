#include <bits/stdc++.h>

using namespace std;

void insert(stack<int> &s, int x)
{
    if (s.size() == 0 || s.top() < x)
    {
        s.push(x);
        return;
    }

    int top = s.top();
    s.pop();
    insert(s, x);
    s.push(top);
}

void sort(stack<int> &s)
{
    if (s.size() == 0 || s.size() == 1)
        return;

    int top = s.top();
    s.pop();
    sort(s);
    insert(s, top);
}

int main()
{
    stack<int> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.push(x);
    }
    sort(s);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}