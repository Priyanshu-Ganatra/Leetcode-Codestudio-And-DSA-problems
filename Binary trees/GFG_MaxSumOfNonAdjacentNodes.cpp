#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

pair<int, int> solve(Node *root)
{
    if (!root)
        return {0, 0};
    auto lSum = solve(root->left);
    auto rSum = solve(root->right);

    // sum including the current node
    int a = root->data + lSum.second + rSum.second;
    // sum excluding the current node
    int b = max(lSum.first, lSum.second) + max(rSum.first, rSum.second);
    return {a, b};
}

// tc: O(n) & sc: O(n)
int getMaxSum(Node *root)
{
    auto ans = solve(root);
    return max(ans.first, ans.second);
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
    cout << "Maximum sum of nodes in a binary tree such that no two adjacent nodes' value taken is: " << endl;
    cout << getMaxSum(root) << endl;
    return 0;
}