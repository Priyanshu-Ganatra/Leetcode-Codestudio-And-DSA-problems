#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// tc: O(n) & sc: O(n)
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (!root)
        return ans;
    bool leftToRight = true;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) // for each level
    {
        int size = q.size();           // size of current level
        vector<int> level(size);       // vector to store current level
        for (int i = 0; i < size; i++) // for each node in current level
        {
            TreeNode *node = q.front();                 // get node from front of queue
            q.pop();                                    // remove node from queue
            int index = leftToRight ? i : size - i - 1; // if left to right, store node from left to right, else store from right to left
            level[index] = node->val;                   // store node in level vector
            if (node->left)                             // if left child exists, push it to queue
                q.push(node->left);
            if (node->right) // if right child exists, push it to queue
                q.push(node->right);
        }
        leftToRight = !leftToRight; // toggle leftToRight
        ans.push_back(level);      // store level in ans
    }
    return ans; // return ans
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    vector<vector<int>> ans = zigzagLevelOrder(root);
    cout << "ZigZag traversal of binary tree is: " << endl;
    for (auto v : ans)
    {
        for (auto x : v)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}