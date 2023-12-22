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

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL)
        return NULL;
    if (root == p || root == q)
        return root;

    // solve for left subtree
    TreeNode *leftAns = lowestCommonAncestor(root->left, p, q);

    // solve for right subtree
    TreeNode *rightAns = lowestCommonAncestor(root->right, p, q);

    if (leftAns != NULL && rightAns != NULL)
        return root;
    else if (leftAns != NULL)
        return leftAns;
    else if (rightAns != NULL)
        return rightAns;
    else
        return NULL;
}

int main()
{
    TreeNode *root = new TreeNode(3);
    TreeNode *left = new TreeNode(5);
    TreeNode *right = new TreeNode(1);
    root->left = left;
    root->right = right;
    TreeNode *leftLeft = new TreeNode(6);
    TreeNode *leftRight = new TreeNode(2);
    left->left = leftLeft;
    left->right = leftRight;
    TreeNode *rightLeft = new TreeNode(0);
    TreeNode *rightRight = new TreeNode(8);
    right->left = rightLeft;
    right->right = rightRight;
    TreeNode *leftRightLeft = new TreeNode(7);
    TreeNode *leftRightRight = new TreeNode(4);
    leftRight->left = leftRightLeft;
    leftRight->right = leftRightRight;

    TreeNode *ans = lowestCommonAncestor(root, left, right);
    cout << "LCA : " << ans->val << endl;
    return 0;
}