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

// void inorder(TreeNode *root, vector<int> &nodes)
// {
//     if (!root)
//     {
//         return;
//     }
//     inorder(root->left, nodes);
//     nodes.push_back(root->val);
//     inorder(root->right, nodes);
// }

// // recursive approach - tc: O(n) & sc: O(n)
// vector<int> inorderTraversal(TreeNode *root)
// {
//     vector<int> nodes;
//     inorder(root, nodes);
//     return nodes;
// }

// morris traversal - tc: O(n) & sc: O(1)
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    TreeNode *curr = root;
    while (curr)
    {
        // left node == NULL then add curr node to ans and move right (right can point to
        // the inorder successor of curr node as well)
        if (curr->left == NULL)
        {
            ans.push_back(curr->val);
            curr = curr->right;
        }
        // left node isn't NULL
        else
        {
            // find inorder predeccessor of left/curr node and make that predecessor node's
            // right pointer point to the left node (thread linking) so that we can can
            // reach back to left node after its left node/subtree has been processed

            // steps to find predeccesor of left/curr node
            // 1. go to left node of curr node 1 time
            // 2. move right until the right pointer is just before NULL node
            TreeNode *pred = curr->left;
            // curr pointer will comeback to its position through thread link after its left
            // node has been added to ans, so to not get stuck in a loop again going from
            // current to left node and current again there's this 1st condition below
            while (pred->right != curr && pred->right)
            {
                pred = pred->right;
            }

            // if thread link isn't present from pred to curr, then set it through pred's
            // right pointer
            if (pred->right == NULL)
            {
                pred->right = curr;
                curr = curr->left;
            }
            // if the link is already set, remove it
            else
            {
                pred->right = NULL;
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);
    root->right->right = new TreeNode(11);
    cout << "Inorder traversal of the binary tree is:" << endl;
    vector<int> ans = inorderTraversal(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}