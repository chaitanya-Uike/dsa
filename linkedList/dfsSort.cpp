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

Node *segregate(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *zs, *ze, *os, *oe, *ts, *te;
    zs = ze = oe = os = ts = te = NULL;

    Node *i = head;

    while (i)
    {
        if (i->data == 1)
        {
            if (os == NULL)
                os = oe = i;
            else
            {
                oe->next = i;
                oe = i;
            }
        }
        else if (i->data == 2)
        {
            if (ts == NULL)
                ts = te = i;
            else
            {
                te->next = i;
                te = i;
            }
        }
        else
        {
            if (zs == NULL)
                zs = ze = i;
            else
            {
                ze->next = NULL;
                ze = i;
            }
        }

        i = i->next;
    }

    if (ze != NULL)
        ze->next = os;
    if (oe != NULL)
        oe->next = ts;
    if (te != NULL)
        te->next = NULL;
    if (ze != NULL && oe == NULL && ts != NULL)
        ze->next = ts;

    if (zs)
        return zs;
    if (os)
        return os;
    return zs;
}

int main()
{

    return 0;
}