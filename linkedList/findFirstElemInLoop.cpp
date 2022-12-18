#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head)
{
    if (head == NULL)
        return NULL;

    ListNode *slow = head, *fast = head;

    bool isLoop = false;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
        {
            isLoop = true;
            break;
        }
    }

    if (!isLoop)
        return NULL;

    ListNode *temp = head;
    while (temp != slow)
    {
        temp = temp->next;
        slow = slow->next;
    }

    return temp;
}

int main()
{

    return 0;
}