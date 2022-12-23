#include <bits/stdc++.h>

using namespace std;

void f(string digits, int i, string sub, vector<string> &res, vector<vector<char>> &mapping)
{
    if (sub.length() == digits.length())
    {
        if (sub.length() != 0)
            res.push_back(sub);
        return;
    }

    vector<char> letters = mapping[digits[i] - '0'];

    for (int j = 0; j < letters.size(); j++)
        f(digits, i + 1, sub + letters[j], res, mapping);
}

vector<string> letterCombinations(string digits)
{
    vector<vector<char>> mapping = {
        {},
        {},
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'},
        {'j', 'k', 'l'},
        {'m', 'n', 'o'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v'},
        {'w', 'x', 'y', 'z'}};

    vector<string> res;
    f(digits, 0, "", res, mapping);
    return res;
}

int main()
{
    string digits;
    cin >> digits;

    vector<string> res = letterCombinations(digits);

    for (auto s : res)
        cout << s << endl;

    return 0;
}