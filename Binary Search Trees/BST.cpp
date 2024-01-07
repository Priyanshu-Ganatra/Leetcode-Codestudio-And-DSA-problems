#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

int minValue(Node *root)
{
    if (root == NULL)
        return -1;
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}

int maxValue(Node *root)
{
    if (root == NULL)
        return -1;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}

vector<vector<int>> levelOrder(Node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    queue<Node *> q;
    q.push(root);      // push root node
    while (!q.empty()) // while queue is not empty
    {
        int s = q.size();           // size of queue
        vector<int> v;              // vector to store values of nodes at each level
        for (int i = 0; i < s; i++) // for each level store values of nodes in vector
        {
            Node *node = q.front();  // get front node
            q.pop();                 // pop front node
            if (node->left != NULL)  // if left child exists
                q.push(node->left);  // push left child
            if (node->right != NULL) // if right child exists
                q.push(node->right); // push right child
            v.push_back(node->data); // push value of node
        }
        ans.push_back(v); // push vector of values of nodes at each level
    }
    return ans; // return answer
}

void preOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

Node *insertIntoBST(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }

    if (val < root->data)
    {
        root->left = insertIntoBST(root->left, val);
    }
    else
    {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}

Node *deleteInBST(Node *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->data == key)
    {
        // delete node
        // 4 cases

        // 1. node is leaf node
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // 2. node has right child
        else if (root->left == NULL)
        {
            Node *rightChild = root->right;
            delete root;
            return rightChild;
        }
        // 3. node has left child
        else if (root->right == NULL)
        {
            Node *leftChild = root->left;
            delete root;
            return leftChild;
        }
        // 4. node has both children
        else
        {
            // get max value from left subtree
            int leftMax = maxValue(root->left);
            // replace root value with leftMax
            root->data = leftMax;
            // delete leftMax from left subtree
            root->left = deleteInBST(root->left, leftMax);
            return root;
        }
    }
    else if (root->data > key)
    {
        // go to left subtree
        root->left = deleteInBST(root->left, key);
    }
    else
    {
        // go to right subtree
        root->right = deleteInBST(root->right, key);
    }

    return root;
}

void createBST(Node *&root)
{
    cout << "Enter data: " << endl;
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cout << "Enter data: " << endl;
        cin >> data;
    }
}

// best case: time = O(logn) and space: O(logn)
// worst case: time = O(n) and space: O(n)
bool searchInBST(Node *root, int key)
{
    // base case
    if (root == NULL)
        return false;
    // solve 1 case
    if (root->data == key)
        return true;
    // solve remaining cases using recursion
    if (key < root->data)
        return searchInBST(root->left, key);
    else
        return searchInBST(root->right, key);
}

// time: O(n) and space: O(n)
Node *BSTFromInorder(vector<int> &inorder, int start, int end)
{
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    Node *root = new Node(inorder[mid]);
    root->left = BSTFromInorder(inorder, start, mid - 1);
    root->right = BSTFromInorder(inorder, mid + 1, end);
    return root;
}

int main()
{
    Node *root = NULL;
    createBST(root);
    levelOrder(root);

    cout << "\nLevel Order Traversal: \n";
    for (auto it : levelOrder(root))
    {
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    cout << "Pre Order Traversal: ";
    preOrder(root);
    cout << endl;
    cout << "In Order Traversal: ";
    inOrder(root);
    cout << endl;
    cout << "Post Order Traversal: ";
    postOrder(root);
    cout << endl;
    cout << "Minimum Value in tree: " << minValue(root) << endl;
    cout << "Maximum Value in tree: " << maxValue(root) << endl;
    int t;
    cout << "Enter number to search: ";
    cin >> t;
    if (searchInBST(root, t))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;
    cout << "Enter number to delete: ";
    cin >> t;
    root = deleteInBST(root, t);
    cout << "Inorder Traversal after deletion: ";
    inOrder(root);
    return 0;
}
