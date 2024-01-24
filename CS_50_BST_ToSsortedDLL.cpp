#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void solve(TreeNode<int> *root, TreeNode<int>* &head){
    if(!root) return;
    // RNL
    // R
    solve(root->right, head);
    // N
    root->right = head; // attach root's right to head
    if(head != NULL) // if head is not null then attach head's left to root as this is a doubly linked list
        head->left = root;
    head = root; // make root as the new head
    // L
    solve(root->left, head); 
}

TreeNode<int> *bstToSortedDLL(TreeNode<int> *root)
{
    TreeNode<int> *head = NULL;
    solve(root, head);
    return head;
}

void printList(TreeNode<int> *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->right;
    }
}

int main()
{
    TreeNode<int> *root = new TreeNode<int>(10);
    root->left = new TreeNode<int>(5);
    root->right = new TreeNode<int>(20);
    root->right->left = new TreeNode<int>(30);
    root->right->right = new TreeNode<int>(35);

    TreeNode<int> *head = bstToSortedDLL(root);
    printList(head);
    return 0;
}