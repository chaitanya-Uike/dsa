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

ListNode *oddEvenList(ListNode *head)
{
    if (head == NULL)
        return NULL;

    if (head->next == NULL)
        return head;

    ListNode *even = head;
    ListNode *odd = head->next;
    ListNode *temp = head->next;

    while (odd->next && even->next)
    {
        even->next = even->next->next;
        odd->next = odd->next->next;
        even = even->next;
        odd = odd->next;
    }

    even->next = temp;
    return head;
}

int main()
{

    return 0;
}