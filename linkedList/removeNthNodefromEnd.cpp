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
    while (temp != NULL)
    {
        l++;
        temp = temp->next;
    }

    return l;
}

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if (head == NULL)
        return NULL;

    int l = getLength(head);

    int idx = l - n;

    ListNode *prev = NULL, *temp = head;

    while (idx > 0)
    {
        prev = temp;
        temp = temp->next;
        idx--;
    }

    if (temp == head)
        return head = head->next;

    prev->next = prev->next->next;

    return head;
}

int main()
{

    return 0;
}