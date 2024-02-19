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

pair<int, bool> solve(struct Node *&tree)
{
    if (!tree)
        return {INT_MIN, true};

    if (!tree->left && !tree->right)
    {
        return {tree->data, true};
    }

    pair<int, bool> leftAns = solve(tree->left);
    pair<int, bool> rightAns = solve(tree->right);

    int leftSubtreeNodeVal = leftAns.first;
    int rightSubtreeNodeVal = rightAns.first;
    bool isLeftSubtreeHeap = leftAns.second;
    bool isRightSubtreeHeap = rightAns.second;

    if (tree->data > leftSubtreeNodeVal && tree->data > rightSubtreeNodeVal && isLeftSubtreeHeap && isRightSubtreeHeap)
    {
        return {tree->data, true};
    }
    else
        return {max(tree->data, max(leftSubtreeNodeVal, rightSubtreeNodeVal)), false};
}

bool isCBT(struct Node *root, int i, int n)
{
    if (root == NULL)
        return true;

    if (i >= n)
    {
        return false;
    }
    else
    {

        bool left = isCBT(root->left, 2 * i + 1, n);
        bool right = isCBT(root->right, 2 * i + 2, n);

        return (left && right);
    }
}

int countNodes(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = countNodes(root->left);
    int right = countNodes(root->right);

    return left + right + 1;
}

bool isHeap(struct Node *tree)
{
    pair<int, bool> p = solve(tree);
    int n = countNodes(tree);

    if (isCBT(tree, 0, n) && solve(tree).second)
    {
        return true;
    }

    return false;
}

int main()
{
    struct Node *root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);
    root->left->left->left = new Node(3);
    root->left->left->right = new Node(2);
    root->left->right->left = new Node(1);

    if (isHeap(root))
    {
        cout << "Given binary tree is a Heap\n";
    }
    else
    {
        cout << "Given binary tree is not a Heap\n";
    }

    return 0;
}