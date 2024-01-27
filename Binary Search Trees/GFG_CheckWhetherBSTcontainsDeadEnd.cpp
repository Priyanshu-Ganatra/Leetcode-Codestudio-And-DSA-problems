#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *right, *left;
    Node(int val)
    {
        data = val;
        right = left = NULL;
    }
};

void fun(Node *root, unordered_map<int, bool> &visited, bool &ans)
{
    if (root == 0)
        return;
    // visit the node
    visited[root->data] = 1;
    if (root->left == 0 && root->right == 0)
    {
        // leaf
        int leafValPlus1 = root->data + 1;
        int leafValMinus1 = root->data - 1 == 0 ? root->data : root->data - 1;
        if (visited.find(leafValPlus1) != visited.end() && visited.find(leafValMinus1) != visited.end())
        {
            ans = true;
            return;
        }
    }
    fun(root->left, visited, ans);
    fun(root->right, visited, ans);
}

bool isDeadEnd(Node *root)
{
    bool ans = false;
    unordered_map<int, bool> visited;
    fun(root, visited, ans);
    return ans;
}

// hardcoded driver code
int main()
{
    Node *root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(9);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->left->left->left = new Node(1);
    root->left->right->right = new Node(3);
    root->right->right = new Node(10);
    cout << "Dead End?" << endl;
    cout << isDeadEnd(root);
    return 0;
}