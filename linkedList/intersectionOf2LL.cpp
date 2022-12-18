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
        temp = temp->next;
        l++;
    }

    return l;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    int lA = getLength(headA);
    int lB = getLength(headB);

    int diff = abs(lA - lB);

    ListNode *tempA, *tempB;

    if (lA < lB)
    {
        tempA = headA;
        tempB = headB;
    }
    else
    {
        tempA = headB;
        tempB = headA;
    }

    while (diff--)
        tempB = tempB->next;

    while (tempA != tempB)
    {
        tempA = tempA->next;
        tempB = tempB->next;
    }

    return tempA;
}

int main()
{

    return 0;
}