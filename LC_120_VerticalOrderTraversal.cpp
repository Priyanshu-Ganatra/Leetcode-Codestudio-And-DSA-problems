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
vector<vector<int>> verticalTraversal(TreeNode *root)
{
    vector<vector<int>> ans;
    queue<pair<TreeNode *, pair<int, int>>> q; // Node, {row, col}
    q.push({root, {0, 0}});
    // maps each col to its row wise sorted elems
    // col -> {row: [x, y, z...]}
    map<int, map<int, multiset<int>>> mp;

    while (!q.empty())
    {
        auto front = q.front();
        q.pop();
        TreeNode *&node = front.first; // get node from front of queue
        auto &coords = front.second; // get coords of node (row, col)
        int &row = coords.first;
        int &col = coords.second;
        mp[col][row].insert(node->val);
        if (node->left)
            q.push({node->left, {row + 1, col - 1}}); // left child is one row down and one col left
        if (node->right)
            q.push({node->right, {row + 1, col + 1}}); // right child is one row down and one col right
    }

    // store ans from the map
    for (auto it : mp) // for each column in the map
    {                             
        auto &colMap = it.second; // get each row and the elems in that row
        vector<int> vLine;        // vertical traversal of current col
        for (auto colMapIt : colMap) // traverse each row in the col
        {                                 
            auto &mset = colMapIt.second; // save each row's elements
            // concat to vertical traversal vector
            vLine.insert(vLine.end(), mset.begin(), mset.end());
        }
        // after the vertical traversal of each col is found, store it in ans
        ans.push_back(vLine);
    }
    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> ans = verticalTraversal(root);
    cout << "Vertical Traversal: " << endl;
    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}