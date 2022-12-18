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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *i = l1, *j = l2;
    ListNode *res = NULL;
    ListNode *tail = NULL;
    int carry = 0;

    while (i && j)
    {
        int sum = i->val + j->val;
        int n = (sum % 10) + carry;

        if (n > 9)
        {
            carry = n / 10;
            n = n % 10;
        }
        else
            carry = sum / 10;

        ListNode *newNode = new ListNode(n);
        if (res == NULL)
            res = tail = newNode;
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        i = i->next;
        j = j->next;
    }

    while (i)
    {
        int n = i->val + carry;
        if (n > 9)
        {
            carry = n / 10;
            n = n % 10;
        }
        else
            carry = 0;
        ListNode *newNode = new ListNode(n);
        tail->next = newNode;
        tail = newNode;
        i = i->next;
    }
    while (j)
    {
        int n = j->val + carry;
        if (n > 9)
        {
            carry = n / 10;
            n = n % 10;
        }
        else
            carry = 0;
        ListNode *newNode = new ListNode(n);
        tail->next = newNode;
        tail = newNode;
        j = j->next;
    }

    if (carry > 0)
    {
        ListNode *newNode = new ListNode(carry);
        tail->next = newNode;
        tail = newNode;
    }

    return res;
}

int main()
{

    return 0;
}