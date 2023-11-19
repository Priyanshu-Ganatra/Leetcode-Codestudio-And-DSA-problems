#include <iostream>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

// tc - O(n) & sc - O(n)
Node *oldHelper(Node *head, unordered_map<Node *, Node *> &mp)
{
    if (head == nullptr)
        return nullptr;

    Node *newHead = new Node(head->val);
    mp[head] = newHead;
    newHead->next = oldHelper(head->next, mp);
    if (head->random)
    {
        newHead->random = mp[head->random];
    }
    return newHead;
}

Node *copyRandomList(Node *head)
{
    unordered_map<Node *, Node *> mp;
    return oldHelper(head, mp);
}

// Function to print the linked list
void printList(Node *head)
{
    while (head)
    {
        cout << "Node " << head->val << " - Random: ";
        if (head->random)
        {
            cout << head->random->val;
        }
        else
        {
            cout << "NULL";
        }
        cout << endl;
        head = head->next;
    }
}

int main()
{
    // Creating a sample linked list with random pointers
    Node *head = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);

    head->next = node2;
    head->random = node3;

    node2->next = node3;
    node2->random = head;

    node3->next = nullptr;
    node3->random = node2;

    // Copying the random linked list
    Node *copiedList = copyRandomList(head);

    // Printing the original and copied linked lists
    cout << "Original Linked List:" << endl;
    printList(head);

    cout << "\nCopied Linked List: (Deepcopy)" << endl;
    printList(copiedList);

    return 0;
}
