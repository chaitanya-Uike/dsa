#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

class LinkedList
{
    ListNode *head, *tail;

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    LinkedList(vector<int> v)
    {
        head = NULL;
        tail = NULL;
        for (auto i : v)
        {
            insertAtEnd(i);
        }
    }

    LinkedList(int a[], int n)
    {
        head = NULL;
        tail = NULL;
        for (int i = 0; i < n; i++)
        {
            insertAtEnd(a[i]);
        }
    }

    ListNode *getNewNode(int x)
    {
        ListNode *newNode = new ListNode();
        newNode->val = x;
        newNode->next = NULL;
        return newNode;
    }

    void insertAtFront(int x)
    {
        ListNode *newNode = getNewNode(x);
        newNode->next = head;
        if (head == NULL)
            tail = newNode;
        head = newNode;
    }

    void insertAtEnd(int x)
    {
        ListNode *newNode = getNewNode(x);
        if (head == NULL)
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void print()
    {
        ListNode *temp = head;

        while (temp != NULL)
        {
            cout << temp->val;
            if (temp->next != NULL)
                cout << "->";
            temp = temp->next;
        }
        cout << endl;
    }

    void reverse()
    {
        if (head == NULL || head->next == NULL)
            return;

        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next = head->next;

        while (curr != NULL)
        {
            curr->next = prev;
            prev = curr;
            curr = next;
            if (next != NULL)
                next = next->next;
        }

        head = prev;
    }

    void reverse(ListNode *dummyHead)
    {
        if (head == NULL || head->next == NULL)
            return;

        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next = head->next;

        while (curr != NULL)
        {
            curr->next = prev;
            prev = curr;
            curr = next;
            if (next != NULL)
                next = next->next;
        }

        dummyHead = prev;
    }

    ListNode *getMiddleElem()
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast->next != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    ListNode *getHead()
    {
        return head;
    }
};

class Solution : public LinkedList
{
public:
    Solution(vector<int> v) : LinkedList(v)
    {
    }

    bool isPallindrome()
    {
        ListNode *mid = getMiddleElem();
        reverse(mid->next);

        ListNode *temp1 = getHead();
        ListNode *temp2 = mid->next;

        while (temp2 != NULL)
        {
            if (temp1->val != temp2->val)
                return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }
};

int main()
{
    vector<int> v = {1, 2, 2, 1};
    Solution s(v);
    cout << s.isPallindrome();
    return 0;
}