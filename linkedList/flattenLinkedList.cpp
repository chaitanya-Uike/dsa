#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;
};

class LinkedList
{
    Node *head;
    Node *tail;

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    LinkedList(vector<pair<int, vector<int>>> v)
    {
        head = NULL;
        tail = NULL;
        for (auto it : v)
        {
            Node *subHead = insert(it.first);
            insertSub(subHead, it.second);
        }
    }

    Node *getNode(int x)
    {
        Node *newNode = new Node();
        newNode->data = x;
        newNode->next = NULL;
        newNode->bottom = NULL;
        return newNode;
    }

    Node *insert(int x)
    {
        Node *newNode = getNode(x);

        if (head == NULL)
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        return newNode;
    }

    void insertSub(Node *subHead, vector<int> sub)
    {
        Node *subTail = NULL;
        for (auto i : sub)
        {
            Node *newNode = getNode(i);
            if (subHead->bottom == NULL)
            {
                subHead->bottom = newNode;
                subTail = newNode;
            }
            else
            {
                subTail->bottom = newNode;
                subTail = newNode;
            }
        }
    }

    void print()
    {
        Node *it = head;

        while (it != NULL)
        {
            Node *sub = it;
            while (sub != NULL)
            {
                cout << sub->data;
                if (sub->bottom != NULL)
                    cout << "->";
                sub = sub->bottom;
            }
            if (it->next != NULL)
                cout << "\n|\n";

            it = it->next;
        }
    }

    Node *flatten()
    {
        Node *res = NULL;
        Node *resTail = NULL;
        vector<Node *> ptr;
        Node *it = head;
        while (it != NULL)
        {
            Node *temp = it;
            ptr.push_back(temp);
            it = it->next;
        }

        while (true)
        {
            int min_ = INT_MAX;
            int mIdx;
            bool flag = false;
            for (int i = 0; i < ptr.size(); i++)
            {
                Node *p = ptr[i];
                if (p != NULL && p->data < min_)
                {
                    min_ = p->data;
                    mIdx = i;
                    flag = true;
                }
            }
            if (!flag)
                return res;

            ptr[mIdx] = ptr[mIdx]->bottom;
            Node *newNode = getNode(min_);

            if (res == NULL)
                res = resTail = newNode;
            else
            {
                resTail->bottom = newNode;
                resTail = newNode;
            }
        }

        return res;
    }

    void printFlatten()
    {
        Node *flatHead = flatten();

        while (flatHead != NULL)
        {
            cout << flatHead->data << "->";
            flatHead = flatHead->bottom;
        }
        cout << endl;
    }

    Node *getHead()
    {
        return head;
    }
};

int main()
{
    vector<pair<int, vector<int>>> v = {{5, {7, 8, 10}}, {10, {20}}, {19, {22, 50}}, {28, {35, 40, 45}}};
    LinkedList ll(v);
    // ll.print();
    cout << endl;
    ll.printFlatten();
    return 0;
}