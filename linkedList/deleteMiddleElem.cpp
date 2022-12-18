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

ListNode *deleteMiddle(ListNode *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
        return NULL;

    ListNode *slow = head, *fast = head;

    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    int l = getLength(head);

    if (l % 2 == 0)
        slow->next = slow->next->next;
    else
    {
        slow->val = slow->next->val;
        slow->next = slow->next->next;
    }

    return head;
}

int main()
{

    return 0;
}