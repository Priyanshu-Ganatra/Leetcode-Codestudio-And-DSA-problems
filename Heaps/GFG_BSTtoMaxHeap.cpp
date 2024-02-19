#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// LNR
void inorder(Node *root, vector<int> &in)
{
    if (!root)
        return;
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

// LRN
void fillUsingPostorder(Node *root, vector<int> &in, int &i)
{
    if (!root)
        return;
    fillUsingPostorder(root->left, in, i);
    fillUsingPostorder(root->right, in, i);
    root->data = in[i++];
}

void convertToMaxHeapUtil(Node *root)
{
    vector<int> in;
    inorder(root, in);
    int index = 0;
    fillUsingPostorder(root, in, index);
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    convertToMaxHeapUtil(root);

    return 0;
}