#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};

vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{
    Node *temp = head;
    Node *tail = head;
    vector<pair<int, int>> res;

    while (tail->next)
        tail = tail->next;

    while (temp != tail && temp->prev != tail)
    {
        int sum = tail->data + temp->data;

        if (sum == target)
        {
            res.push_back(pair<int, int>(temp->data, tail->data));
            temp = temp->next;
            tail = tail->prev;
        }
        else if (sum < target)
            temp = temp->next;
        else
            tail = tail->prev;
    }
    return res;
}

int main()
{

    return 0;
}