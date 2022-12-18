#include <bits/stdc++.h>

using namespace std;

vector<string> split(string str, char del)
{
    vector<string> v;
    string curr = "";
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == del)
        {
            v.push_back(curr);
            curr = "";
        }
        else
            curr += str[i];
    }

    if (curr != "")
        v.push_back(curr);

    return v;
}

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node()
    {
        left = NULL;
        right = NULL;
    }

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class BST
{
    Node *root;

    Node *insert(Node *root, int x)
    {
        if (root == NULL)
        {
            Node *newNode = new Node(x);
            return newNode;
        }

        if (x > root->data)
            root->right = insert(root->right, x);
        else if (x < root->data)
            root->left = insert(root->left, x);

        return root;
    }

    Node *search(Node *root, int x)
    {
        if (root == NULL)
            return NULL;

        if (x > root->data)
            return search(root->right, x);
        if (x < root->data)
            return search(root->left, x);

        return root;
    }

    void inorder(Node *root)
    {
        if (root == NULL)
            return;

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void preorder(Node *root)
    {
        if (root == NULL)
            return;

        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node *root)
    {
        if (root == NULL)
            return;

        preorder(root->left);
        preorder(root->right);
        cout << root->data << " ";
    }

    Node *getMin(Node *root)
    {
        if (root != NULL && root->left != NULL)
            return getMin(root->left);

        return root;
    }

    Node *delete_(Node *root, int x)
    {
        if (root == NULL)
            return root;

        if (x > root->data)
            root->right = delete_(root->right, x);

        else if (x < root->data)
            root->left = delete_(root->left, x);
        else
        {
            Node *temp = NULL;
            // case 1: leaf Node
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
            // case 2: single child
            else if (root->left == NULL && root->right != NULL)
            {
                temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL && root->left != NULL)
            {
                temp = root->left;
                delete root;
                return temp;
            }
            // case 3: both child present
            else
            {
                temp = getMin(root->right);
                int d = temp->data;
                root->right = delete_(root->right, d);
                root->data = d;
            }
        }

        return root;
    }

    int maxHeight(Node *root, int &max_)
    {
        if (root == NULL)
            return 0;
        int l = maxHeight(root->left, max_);
        int r = maxHeight(root->right, max_);
        max_ = max(max_, l + r);
        return max(l, r) + 1;
    }

    Node *parser(vector<string> &v, int rootIndex)
    {
        if (rootIndex > v.size() || v[rootIndex - 1] == "N")
            return NULL;

        Node *newNode = new Node(stoi(v[rootIndex - 1]));
        newNode->left = parser(v, rootIndex * 2);
        newNode->right = parser(v, rootIndex * 2 + 1);

        return newNode;
    }

public:
    BST()
    {
        root = NULL;
    }

    void insertNode(int x)
    {
        root = insert(root, x);
    }

    Node *searchNode(int x)
    {
        return search(root, x);
    }

    void inorderTraversal()
    {
        inorder(root);
        cout << endl;
    }

    void preorderTraversal()
    {
        preorder(root);
        cout << endl;
    }

    void postorderTraversal()
    {
        postorder(root);
        cout << endl;
    }

    void deleteNode(int x)
    {
        root = delete_(root, x);
    }

    // int getMaxheight()
    // {
    //     return maxHeight(root);
    // }

    int getDiameter()
    {
        int diameter = 0;
        maxHeight(root, diameter);
        return diameter;
    }

    string serializer()
    {
        string res = "";
        queue<Node *> q;

        q.push(root);

        while (!q.empty())
        {
            Node *top = q.front();
            q.pop();
            if (top != NULL)
            {
                res += to_string(top->data) + " ";
                q.push(top->left);
                q.push(top->right);
            }
            else
            {
                res += "N ";
            }
        }

        // remove extra NULLs
        int i = res.size() - 1;
        while (res[i] == 'N' || res[i] == ' ')
            i--;

        return res.substr(0, i + 1);
    }

    void deserializer(string str)
    {
        vector<string> v = split(str, ' ');
        root = parser(v, 1);
    }
};

int main()
{
    BST b1, b2;
    // b1.insertNode(7);
    // b1.insertNode(6);
    // b1.insertNode(9);
    // b1.insertNode(4);
    // b1.insertNode(3);
    // b1.insertNode(8);
    // b1.insertNode(10);

    b1.deserializer("1 2 3 N N 4 5 6 7");
    b1.inorderTraversal();
    // b2.deserializer(b1.serializer());
    // cout << b2.serializer();

    return 0;
}