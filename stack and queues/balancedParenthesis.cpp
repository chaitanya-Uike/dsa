#include <bits/stdc++.h>

using namespace std;

bool isBalanced(string str)
{
    stack<int> s;
    unordered_map<char, int> map = {{'(', 1},
                                    {')', -1},
                                    {'{', 2},
                                    {'}', -2},
                                    {'[', 3},
                                    {']', -3}};

    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if (map.find(ch)->second > 0)
        {
            s.push(ch);
        }
        else
        {
            if (map.find(s.top())->second + map.find(ch)->second == 0)
                s.pop();
            else
                return false;
        }
    }

    return s.empty();
}

int main()
{
    string str;
    cin >> str;
    cout << isBalanced(str);
    return 0;
}