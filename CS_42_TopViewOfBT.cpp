#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T dat)
    {
        this->data = dat;
        left = NULL;
        right = NULL;
    }
};

vector<int> getTopView(TreeNode<int> *root)
{
    map<int, int> hdToNode;
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        pair<TreeNode<int> *, int> temp = q.front();
        q.pop();
        TreeNode<int> *frontNode = temp.first;
        int hd = temp.second;

        // if no entry for this hd exists, then add it in the map
        if (hdToNode.find(hd) == hdToNode.end())
        {
            hdToNode[hd] = frontNode->data;
        }

        // children
        if (frontNode->left != NULL)
        {
            q.push({frontNode->left, hd - 1});
        }
        if (frontNode->right != NULL)
        {
            q.push({frontNode->right, hd + 1});
        }
    }
    vector<int> ans;
    for (auto i : hdToNode)
    {
        ans.push_back(i.second);
    }
    return ans;
}

int main()
{
    // considering tree as
    //      1
    //     / \
    //    2   3
    //   / \   \
    //  4   5   6
    //     /
    //    7
    TreeNode<int> *root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->left->right = new TreeNode<int>(5);
    root->left->right->left = new TreeNode<int>(7);
    root->right = new TreeNode<int>(3);
    root->right->right = new TreeNode<int>(6);
    root->left->left = new TreeNode<int>(4);
    vector<int> ans = getTopView(root);
    cout << "Top view of the tree is : ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}