#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// tc - O(h) & sc - O(1)
Node *inOrderSuccessor(Node *root, Node *x)
{
    Node *succ = 0;
    Node *curr = root;
    while (curr)
    {
        if (curr->data > x->data)
        {
            succ = curr;
            curr = curr->left;
        }
        else
            curr = curr->right;
    }
    return succ;
}

int main()
{
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);

    root->left->left = new Node(4);
    root->left->right = new Node(12);

    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    Node *x = root->left->right->right;

    Node *ans = inOrderSuccessor(root, x);
    if (ans == NULL)
        cout << "No successor Found\n";
    else
        cout << "Successor is " << ans->data << "\n";
    return 0;
}