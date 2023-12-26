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

class Solution
{
public:
    // // recursive approach
    // int maxDepth(TreeNode *root)
    // {
    //     // base case
    //     if (root == NULL)
    //     {
    //         return 0;
    //     }

    //     int leftHeight = maxDepth(root->left);
    //     int rightHeight = maxDepth(root->right);
    //     int height = max(leftHeight, rightHeight) + 1; // +1 for root node
    //     return height;
    // }

    // using level order traversal
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        int height = 0;
        while (!q.empty())
        {
            int s = q.size();
            for (int i = 0; i < s; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
            }
            height++;
        }
        return height;
    }
};

int main()
{
    Solution obj;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    // root->right->left = new TreeNode(15);
    // root->right->right = new TreeNode(7);
    cout << obj.maxDepth(root) << endl;
    return 0;
}