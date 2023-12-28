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

// tc: O(n), sc: O(n)
bool isSameTree(TreeNode *p, TreeNode *q)
{
    // leaf node
    if (!p && !q)
        return true;
    // both are some valid node
    else if (p && q)
    {
        return (p->val == q->val) &&
               isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
    // if either of them is NULL it means tree isn't identical
    else
        return false;
}

int main()
{
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);

    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);

    cout << "Is same tree:" << endl;
    cout << isSameTree(root1, root2) << endl;
    return 0;
}