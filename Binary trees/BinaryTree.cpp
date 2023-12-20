#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// returns the root of the tree
Node *createTree()
{
    int data;
    cout << "Enter the data " << endl;
    cin >> data;
    if (data == -1) // if data is -1 then it means that there is no node, base case
    {
        return NULL;
    }
    // step 1: create a node
    Node *root = new Node(data);
    // step 2: create left subtree
    cout << "Enter the left child of " << data << " ";
    root->left = createTree();
    // step 3: create right subtree
    cout << "Enter the right child of " << data << " ";
    root->right = createTree();
    return root;
}

void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    Node *root = createTree();
    cout << root->data << endl;
    cout << "Preorder traversal: ";
    preOrder(root);
    cout << endl;
    cout << "Inorder traversal: ";
    inOrder(root);
    cout << endl;
    cout << "Postorder traversal: ";
    postOrder(root);
    cout << endl;
    return 0;
}