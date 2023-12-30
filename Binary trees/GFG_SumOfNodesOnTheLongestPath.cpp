#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

pair<int, int> height(Node *root)
{
    if (!root)
        return {0, 0};

    auto lh = height(root->left);
    auto rh = height(root->right);

    int sum = root->data;
    if (lh.first == rh.first)
    {
        sum += lh.second > rh.second ? lh.second : rh.second;
    }
    else if (lh.first > rh.first)
    {
        sum += lh.second;
    }
    else
    {
        sum += rh.second;
    }

    return {max(lh.first, rh.first) + 1, sum};
}

// tc: O(n) & sc: O(n)
int sumOfLongRootToLeafPath(Node *root)
{
    auto h = height(root);
    return h.second;
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(7);
    root->left->right = new Node(1);
    root->right->left = new Node(2);
    root->right->right = new Node(3);
    cout << "Sum of nodes on the longest path from root to leaf node is: " << endl;
    cout << sumOfLongRootToLeafPath(root) << endl;
    return 0;
}