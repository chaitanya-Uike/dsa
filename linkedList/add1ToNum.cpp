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

Node *reverse(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *rev = NULL;
    Node *temp = head;
    Node *next = NULL;

    while (temp)
    {
        next = temp->next;
        temp->next = rev;
        rev = temp;
        temp = next;
    }

    return rev;
}

Node *addOne(Node *head)
{
    head = reverse(head);
    Node *temp = head;

    while (temp)
    {
        if (temp->data != 9)
        {
            temp->data++;
            break;
        }
        else
        {
            temp->data = 0;
            if (temp->next == NULL)
            {
                Node *newNode = new Node(1);
                temp->next = newNode;
            }
        }
        temp = temp->next;
    }

    return reverse(head);
}

int main()
{

    return 0;
}