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

void swap(ListNode *x, ListNode *y)
{
    int z = x->val;
    x->val = y->val;
    y->val = z;
}

ListNode *partition(ListNode *head, ListNode *end)
{
    ListNode *i = head;
    ListNode *j = head;
    ListNode *temp = NULL;

    while (j != end)
    {
        if (j->val <= head->val)
        {
            swap(j, i);
            temp = i;
            i = i->next;
        }
        j = j->next;
    }

    swap(head, temp);

    return temp;
}

void quickSort(ListNode *head, ListNode *end)
{
    if (head == NULL)
        return;

    if (head != end)
    {
        ListNode *p = partition(head, end);
        quickSort(head, p);
        quickSort(p->next, end);
    }
}

ListNode *sortList(ListNode *head)
{
    quickSort(head, NULL);

    return head;
}

int main()
{

    return 0;
}