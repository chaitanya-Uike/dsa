#include <bits/stdc++.h>

using namespace std;

bool backtracker(vector<vector<char>> &board, string word, int i, int j, string currWord)
{
    int m = board.size();
    int n = board[0].size();
    if (i < 0 || j < 0 || i >= m || j >= n)
        return false;

    if (currWord == word)
        return true;

    bool isViable = false;

    currWord += board[i][j];

    int l = currWord.length() - 1;

    if (currWord[l] == word[l])
    {
        board[i][j] = '*';
        isViable = backtracker(board, word, i - 1, j, currWord) || backtracker(board, word, i, j + 1, currWord) || backtracker(board, word, i + 1, j, currWord) || backtracker(board, word, i, j - 1, currWord);
        board[i][j] = currWord[l];
    }

    return isViable;
}

bool exist(vector<vector<char>> &board, string word)
{
    int m = board.size();
    int n = board[0].size();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            if (backtracker(board, word, i, j, ""))
                return true;
    }

    return false;
}

int main()
{
    int m, n;
    cin >> m >> n;
    string word;
    cin >> word;
    vector<vector<char>> board(m, vector<char>(n));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    cout << exist(board, word);

    return 0;
}