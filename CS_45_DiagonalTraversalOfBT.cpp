#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};

// void solve(BinaryTreeNode<int> *root, int d, map<int, vector<int>> &diagTrav)
// {
//     if (!root)
//         return;
//     diagTrav[d].push_back(root->data);
//     solve(root->left, d + 1, diagTrav);
//     solve(root->right, d, diagTrav);
// }

// // brute force approach : tc : O(n) sc : O(n)
// vector<int> diagonalPath(BinaryTreeNode<int> *root)
// {
//     int d = 0;
//     vector<int> ans;
//     map<int, vector<int>> diagTrav;
//     solve(root, d, diagTrav);
//     for (auto i : diagTrav)
//     {
//         for (int j : i.second)
//         {
//             ans.push_back(j);
//         }
//     }
//     return ans;
// }

// optimised approach : tc : O(n) sc : O(n),
// this solution is similar to level order traversal and is better 
// than the above solution because it does not use map which is an extra space
vector<int> diagonalPath(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    // this queue will store the nodes of the tree
    queue<BinaryTreeNode<int> *> q; 
    // push the root node
    q.push(root);
    // while the queue is not empty 
    while (!q.empty())
    {
        // pop the front node and store it in temp 
        BinaryTreeNode<int> *temp = q.front();
        q.pop();
        // traverse the tree in the right direction and push the nodes in the queue 
        while (temp)
        {
            ans.push_back(temp->data);
            // push the left child of the current node in the queue so that it can be traversed later
            if (temp->left)
            {
                q.push(temp->left);
            }
            // move to the right child of the current node
            temp = temp->right;
        }
    }
    return ans;
}

int main()
{
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(8);
    root->left = new BinaryTreeNode<int>(3);
    root->right = new BinaryTreeNode<int>(10);
    root->left->left = new BinaryTreeNode<int>(1);
    root->left->right = new BinaryTreeNode<int>(6);
    root->right->right = new BinaryTreeNode<int>(14);
    root->right->right->left = new BinaryTreeNode<int>(13);
    root->left->right->left = new BinaryTreeNode<int>(4);
    root->left->right->right = new BinaryTreeNode<int>(7);

    vector<int> ans = diagonalPath(root);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}