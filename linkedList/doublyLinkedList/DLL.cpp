#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

void insert(Node *root, int data)
{
    Node *newNode = new Node(data);

    if (root == NULL)
        root = newNode;
    else
    {
        newNode->next = root;
        root->prev = newNode;
        root = newNode;
    }
}

Node *reverse(Node *root)
{
    Node *rev = NULL;
    Node *temp = root;

    while (root != NULL)
    {
        root->prev = NULL;
        root = root->next;
        temp->next = rev;
        rev = temp;
        temp = root;
    }

    return rev;
}

void traverse(Node *root)
{
    Node *temp = root;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
}

int main()
{
    Node *root = NULL;
    insert(root, 5);

    cout << root->data;

    traverse(root);

    return 0;
}