#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// tc: O(n) sc: O(n)
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (!root)
        return NULL;

    // case 1: p & q are both in left subtree
    if (p->val < root->val && q->val < root->val)
    {
        TreeNode *leftAns = lowestCommonAncestor(root->left, p, q);
        return leftAns;
    }
    // case 2: p & q are both in right subtree
    if (p->val > root->val && q->val > root->val)
    {
        TreeNode *rightAns = lowestCommonAncestor(root->right, p, q);
        return rightAns;
    }
    // // case 3: p is in left subtree and q is in right subtree
    // if (p->val < root->val && q->val > root->val)
    // {
    //     return root;
    // }
    // // case 4: p is in right subtree and q is in left subtree
    // if (p->val > root->val && q->val < root->val)
    // {
    //     return root;
    // }
    return root;
}

int main()
{
    TreeNode *root = new TreeNode(6);
    TreeNode *left = new TreeNode(2);
    TreeNode *right = new TreeNode(8);
    root->left = left;
    root->right = right;
    TreeNode *leftLeft = new TreeNode(0);
    TreeNode *leftRight = new TreeNode(4);
    left->left = leftLeft;
    left->right = leftRight;
    TreeNode *rightLeft = new TreeNode(7);
    TreeNode *rightRight = new TreeNode(9);
    right->left = rightLeft;
    right->right = rightRight;
    TreeNode *leftRightLeft = new TreeNode(3);
    TreeNode *leftRightRight = new TreeNode(5);
    leftRight->left = leftRightLeft;
    leftRight->right = leftRightRight;

    TreeNode *ans = lowestCommonAncestor(root, left, right);
    cout << "LCA : " << ans->val << endl;
    return 0;
}