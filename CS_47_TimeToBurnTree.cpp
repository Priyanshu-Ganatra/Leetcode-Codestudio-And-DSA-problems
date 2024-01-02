#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryTreeNode<int> *makeNodeToParentMappingAndFindTargetNode(BinaryTreeNode<int> *root, unordered_map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> &parentMap, int &start)
{
    // queue to do level order traversal
    queue<BinaryTreeNode<int> *> q;
    BinaryTreeNode<int> *targetNode = NULL;
    q.push(root);
    parentMap[root] = NULL; // root has no parent
    while (!q.empty()) // doing level order traversal
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        // if the current node is the target node, store it in targetNode
        if (front->data == start) 
        {
            targetNode = front;
        }
        // pushing the children of the current node in the queue
        if (front->left)
        {
            parentMap[front->left] = front;
            q.push(front->left);
        }
        if (front->right)
        {
            parentMap[front->right] = front;
            q.push(front->right);
        }
    }
    return targetNode;
}

int burnTheTree(BinaryTreeNode<int> *root, unordered_map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> &parentMap, BinaryTreeNode<int> *targetNode)
{
    // this map will store if a node is burnt or not i.e. visited or not
    unordered_map<BinaryTreeNode<int> *, bool> isBurnt;
    queue<BinaryTreeNode<int> *> q; // currently burning nodes
    int T = 0;
    q.push(targetNode);
    isBurnt[targetNode] = true;
    // doing level order traversal
    while (!q.empty())
    {
        int size = q.size();
        // if the fire has spread out from the current node, increment T
        bool hasFireSpreadOutFromCurrNode = false;
        // burning the nodes in the queue and pushing their children in the queue
        for (int i = 0; i < size; i++)
        {
            BinaryTreeNode<int> *front = q.front();
            q.pop();
            if (front->left && !isBurnt[front->left])
            {
                q.push(front->left);
                isBurnt[front->left] = true;
                hasFireSpreadOutFromCurrNode = true;
            }
            if (front->right && !isBurnt[front->right])
            {
                q.push(front->right);
                isBurnt[front->right] = true;
                hasFireSpreadOutFromCurrNode = true;
            }
            if (parentMap[front] && !isBurnt[parentMap[front]])
            {
                q.push(parentMap[front]);
                isBurnt[parentMap[front]] = true;
                hasFireSpreadOutFromCurrNode = true;
            }
        }
        // if the fire has spread out from the current node, increment T
        if (hasFireSpreadOutFromCurrNode)
            T++;
    }
    return T;
}

// tc: O(n), sc: O(n)
int timeToBurnTree(BinaryTreeNode<int> *root, int start)
{
    // this map will store the parent of each node
    unordered_map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> parentMap;
    // finding the target node and making the parent map
    BinaryTreeNode<int> *targetNode = makeNodeToParentMappingAndFindTargetNode(root, parentMap, start);
    // burning the tree and returning the time
    return burnTheTree(root, parentMap, targetNode);
}

int main()
{
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    root->left = new BinaryTreeNode<int>(14);
    root->right = new BinaryTreeNode<int>(3);
    root->left->left = new BinaryTreeNode<int>(7);
    root->left->right = new BinaryTreeNode<int>(6);
    root->right->left = new BinaryTreeNode<int>(5);
    root->right->right = new BinaryTreeNode<int>(4);
    root->right->right->left = new BinaryTreeNode<int>(2);
    root->right->right->right = new BinaryTreeNode<int>(8);
    int start = 14;
    cout << "Time to burn the tree: ";
    cout << timeToBurnTree(root, start) << endl;
    return 0;
}
