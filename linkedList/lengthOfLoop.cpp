#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int countNodesinLoop(struct Node *head)
{
    if (head == NULL)
        return 0;

    Node *slow = head, *fast = head;
    bool isLooping = false;

    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast)
        {
            break;
            isLooping = true;
        }
    }

    if (!isLooping)
        return 0;

    Node *temp = head;
    while (temp != slow)
    {
        temp = temp->next;
        slow = slow->next;
    }

    int len = 0;
    slow = slow->next;

    while (slow != temp)
    {
        slow = slow->next;
        len++;
    }

    return len;
}

int main()
{

    return 0;
}