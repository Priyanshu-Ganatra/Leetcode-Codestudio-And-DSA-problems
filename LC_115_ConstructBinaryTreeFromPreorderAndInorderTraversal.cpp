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

// create a mapping of inorder elements with their indices for faster search
void createMapping(vector<int> &inorder, int &size, unordered_map<int, int> &mapping)
{
    for (int i = 0; i < size; i++)
    {
        mapping[inorder[i]] = i;
    }
}

TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int &preIndex, int inStartIndex, int inEndIndex, int &size, unordered_map<int, int> &mapping)
{
    // base case
    if (preIndex >= size || inStartIndex > inEndIndex)
    {
        return NULL;
    }

    // solving one case
    int elem = preorder[preIndex];
    preIndex++;
    TreeNode *root = new TreeNode(elem);
    // search this elem in in-order
    int pos = mapping[elem];

    // recursion
    // left subtree will be from inStartIndex to pos - 1 in inorder as pos is the current root
    root->left = solve(preorder, inorder, preIndex, inStartIndex, pos - 1, size, mapping);
    // right subtree will be from pos + 1 to inEndIndex in inorder as pos is the current root 
    root->right = solve(preorder, inorder, preIndex, pos + 1, inEndIndex, size, mapping);
    return root;
}

// tc : O(n) + O(n) = O(n) for creating mapping and solving and sc : O(n) for mapping and O(h) for recursion stack = O(n)
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int size = preorder.size();
    unordered_map<int, int> mapping; // mapping of inorder elements with their indices
    createMapping(inorder, size, mapping); // create mapping
    int preIndex = 0, inStartIndex = 0, inEndIndex = inorder.size() - 1;
    return solve(preorder, inorder, preIndex, inStartIndex, inEndIndex, size, mapping);
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