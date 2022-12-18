#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int getLength(ListNode *head)
{
    if (head == NULL)
        return 0;
    int l = 0;
    ListNode *temp = head;

    while (temp)
    {
        l++;
        temp = temp->next;
    }

    return l;
}

pair<ListNode *, ListNode *> reverseGroup(ListNode *head, int k)
{
    ListNode *temp = head, *rev = NULL, *tail = NULL, *next = NULL;

    while (k-- && temp)
    {
        if (k == 0)
            next = temp->next;
        if (rev == NULL)
            rev = tail = temp;
        else
        {
            temp->next = rev;
            rev = temp;
        }
        temp = temp->next;
    }
    tail->next = next;

    return pair<ListNode *, ListNode *>(rev, tail);
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    int l = getLength(head);
    int nGroups = l / k;
}

int main()
{

    return 0;
}