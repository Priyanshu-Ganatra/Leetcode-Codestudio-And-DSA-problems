#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// morris traversal - tc: O(n) & sc: O(1)
int findNodesCount(Node *&root)
{
    int count = 0;
    Node *curr = root;
    while (curr)
    {
        // left node == NULL then add curr node to ans and move right (right can point to
        // the inorder successor of curr node as well)
        if (curr->left == NULL)
        {
            count++;
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
            Node *pred = curr->left;
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
                count++;
                curr = curr->right;
            }
        }
    }
    return count;
}

// morris traversal - tc: O(n) & sc: O(1)
float getMedianUsingCount(Node *&root, int &n)
{
    int i = 0;
    int odd1 = (n + 1) / 2, odd1Val = -1;
    int even1 = n / 2, even1Val = -1;
    int even2 = n / 2 + 1, even2Val = -1;
    Node *curr = root;
    while (curr)
    {
        // left node == NULL then add curr node to ans and move right (right can point to
        // the inorder successor of curr node as well)
        if (curr->left == NULL)
        {
            i++;
            if (i == odd1)
                odd1Val = curr->data;
            if (i == even1)
                even1Val = curr->data;
            if (i == even2)
                even2Val = curr->data;
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
            Node *pred = curr->left;
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
                i++;
                if (i == odd1)
                    odd1Val = curr->data;
                if (i == even1)
                    even1Val = curr->data;
                if (i == even2)
                    even2Val = curr->data;
                curr = curr->right;
            }
        }
    }
    float median = 0;
    if ((n & 1) == 0)
        median = (even1Val + even2Val) / 2.0; // even no. of elems
    else
        median = odd1Val;
    return median;
}

// tc: O(n) & sc: O(1)
float findMedian(struct Node *root)
{
    int n = findNodesCount(root);
    return getMedianUsingCount(root, n);
}

int main()
{
    Node *root = new Node(50);
    root->left = new Node(30);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right = new Node(70);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    cout << "Median of BST:" << endl;
    cout << findMedian(root) << endl;
    return 0;
}