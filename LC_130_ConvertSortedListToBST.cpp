#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Recursive helper function to construct the BST from the vector
TreeNode *constructBST(const std::vector<int> &values, int start, int end)
{
    if (start > end)
    {
        return nullptr;
    }

    int mid = (start + end) / 2;

    // Create a new TreeNode using the mid value of the vector
    TreeNode *root = new TreeNode(values[mid]);

    // Recursive calls to construct left and right subtrees
    root->left = constructBST(values, start, mid - 1);
    root->right = constructBST(values, mid + 1, end);

    return root;
}

// tc : O(n) sc : O(n)
TreeNode *sortedListToBST(ListNode *head)
{
    // Convert the linked list to a vector
    vector<int> values;
    while (head)
    {
        values.push_back(head->val);
        head = head->next;
    }

    // Construct the BST from the vector using recursive helper function
    return constructBST(values, 0, values.size() - 1);
}

int main()
{
    ListNode *head = new ListNode(-10);
    head->next = new ListNode(-3);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(9);

    TreeNode *root = sortedListToBST(head);

    return 0;
}