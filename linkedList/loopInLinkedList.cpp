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

    ListNode *insertAtEnd(int x)
    {
        ListNode *newNode = getNewNode(x);
        if (head == NULL)
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        return newNode;
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

    ListNode *detectLoop()
    {
        if (head == NULL || head->next == NULL)
            return NULL;

        ListNode *fast = head;
        ListNode *slow = head;

        while (fast->next != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow)
            {
                ListNode *temp = head;
                while (temp != slow)
                {
                    temp = temp->next;
                    slow = slow->next;
                }

                return slow;
            }
        }

        return NULL;
    }

    ListNode *getTail()
    {
        return tail;
    }
};

int main()
{
    LinkedList ll;

    ll.insertAtEnd(1);
    ll.insertAtEnd(2);
    ListNode *start = ll.insertAtEnd(3);
    ll.insertAtEnd(4);
    ll.insertAtEnd(5);
    ListNode *temp = ll.insertAtEnd(6);
    temp->next = start;

    ListNode *loopStart = ll.detectLoop();
    if (loopStart == NULL)
        cout << "no Loop Present";
    else
        cout << loopStart->val;

    return 0;
}