#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Function to reverse the linked list.
Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *current = head;
    Node *next;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

// Function to add two numbers represented by linked list.
struct Node *addTwoLists(struct Node *first, struct Node *second)
{
    // reversing both lists to simplify addition.
    first = reverse(first);
    second = reverse(second);

    Node *sum = NULL;
    int carry = 0;

    // using a loop till both lists and carry gets exhausted.
    while (first != NULL || second != NULL || carry != 0)
    {
        // using a variable to store sum of two digits along with carry.
        int newVal = carry;

        // if nodes are left in any list, we add their data in newVal.
        if (first)
            newVal += first->data;
        if (second)
            newVal += second->data;

        // updating carry.
        carry = newVal / 10;

        // using modulus to store only a single digit at that place.
        newVal = newVal % 10;

        // creating new node which gets connected with other nodes that
        // we get after calculating sum of respective digits.
        Node *newNode = new Node(newVal);

        // storing the previously made nodes in the link part of new node.
        newNode->next = sum;

        // making the new node as the first node of all previously made node.
        sum = newNode;

        // moving ahead in both lists.
        if (first)
            first = first->next;
        if (second)
            second = second->next;
    }
    return sum;
}

// Function to insert at beginning.
void insertAtHead(Node *&head, Node *&tail, int newData)
{
    Node *newNode = new Node(newData);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

// Function to print the linked list.
void printList(Node *Node)
{
    while (Node != NULL)
    {
        cout << Node->data;
        Node = Node->next;
    }
    cout << "\n";
}

// Simple driver function which passes two linked lists to the above function, and prints the result.
int main()
{
    // LL 1
    Node *head1 = NULL;
    Node *tail1 = NULL;
    insertAtHead(head1, tail1, 9);
    insertAtHead(head1, tail1, 9);
    insertAtHead(head1, tail1, 9);

    // LL 2
    Node *head2 = NULL;
    Node *tail2 = NULL;
    insertAtHead(head2, tail2, 1);

    // answer
    Node *sum = addTwoLists(head1, head2);
    printList(sum);
}