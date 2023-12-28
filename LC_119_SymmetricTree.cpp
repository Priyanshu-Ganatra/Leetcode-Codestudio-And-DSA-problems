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

bool isMirror(TreeNode *p, TreeNode *q)
{
    // leaf node
    if (!p && !q)
        return true;
    // both are some valid node
    else if (p && q)
    {
        if (p->val == q->val)
        {
            // p's left val should be == q's right val & vice versa
            return isMirror(p->left, q->right) && isMirror(p->right, q->left);
        }
        else
            return false;
    }
    // if either of them is NULL it means tree isn't identical
    else
        return false;
}

// tc: O(n), sc: O(n)
bool isSymmetric(TreeNode *root)
{
    return isMirror(root->left, root->right);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    cout << "Is symmetric tree:" << endl;
    cout << isSymmetric(root) << endl;
    return 0;
}
