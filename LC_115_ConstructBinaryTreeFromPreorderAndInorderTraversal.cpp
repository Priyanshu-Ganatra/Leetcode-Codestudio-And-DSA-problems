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

int searchInorder(vector<int> &inorder, int &size, int &target)
{
    for (int i = 0; i < size; i++)
    {
        if (inorder[i] == target)
            return i;
    }
    return -1;
}

TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int &preIndex, int inStartIndex, int inEndIndex, int &size)
{
    // base case
    if (preIndex >= size || inStartIndex > inEndIndex)
    {
        return NULL;
    }

    // one case
    int elem = preorder[preIndex];
    preIndex++;
    TreeNode *root = new TreeNode(elem);
    // search this elem in in-order
    int pos = searchInorder(inorder, size, elem);

    // recursion
    root->left = solve(preorder, inorder, preIndex, inStartIndex, pos - 1, size);
    root->right = solve(preorder, inorder, preIndex, pos + 1, inEndIndex, size);
    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int size = preorder.size();
    int preIndex = 0, inStartIndex = 0, inEndIndex = inorder.size() - 1;
    return solve(preorder, inorder, preIndex, inStartIndex, inEndIndex, size);
}

TreeNode *preOrderTraversal(TreeNode *root)
{
    if (root == NULL)
        return NULL;
    cout << root->val << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
    return root;
}

TreeNode *inOrderTraversal(TreeNode *root)
{
    if (root == NULL)
        return NULL;
    inOrderTraversal(root->left);
    cout << root->val << " ";
    inOrderTraversal(root->right);
    return root;
}

int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    cout << "Given inorder : ";
    for (int elem : inorder)
        cout << elem << " ";
    cout << "\n";
    cout << "Given preorder : ";
    for (int elem : preorder)
        cout << elem << " ";
    cout << endl << endl;
    TreeNode *root = buildTree(preorder, inorder);
    cout << "Inorder traversal from newly constructed tree using given preorder and inorder : ";
    inOrderTraversal(root);
    cout << "\n";
    cout << "Preorder traversal from newly constructed tree using given preorder and inorder : ";
    preOrderTraversal(root);
    cout << "\n";
    return 0;
}