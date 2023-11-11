#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void insertAtHead(ListNode *&head, ListNode *&tail, int data)
{
    // check for Empty LL
    if (head == NULL)
    {
        ListNode *newNode = new ListNode(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        // step1:
        ListNode *newNode = new ListNode(data);
        // step2:
        newNode->next = head;
        // step3:
        head = newNode;
    }
}

void print(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

// Recursive - tc: O(n), sc: O(n)
ListNode *reverseListHelper(ListNode *prev, ListNode *curr)
{
    // base case
    if (curr == NULL)
        return prev; // prevNode is the new head at the end

    // calculation
    ListNode *nextNode = curr->next;    // store next node
    curr->next = prev;                  // reverse current node, it now points to previous node
    prev = curr;                        // update previous node
    curr = nextNode;                    // update current node
    return reverseListHelper(prev, curr);     // recursive call with updated nodes
}

ListNode *reverseList(ListNode *head){
    return reverseListHelper(NULL, head);
}

// Iterative - tc: O(n), sc: O(1)
// ListNode *reverseList(ListNode *head)
// {
//     ListNode *nextNode, *prevNode = NULL, *curr = head;
//     while (curr)
//     {
//         nextNode = curr->next; // store next node
//         curr->next = prevNode; // reverse current node, it now points to previous node
//         prevNode = curr;       // update previous node
//         curr = nextNode;       // update current node
//     }
//     head = prevNode; // prevNode is the new head at the end
//     return head;
// }

int main()
{
    ListNode *head = NULL;
    ListNode *tail = NULL;

    insertAtHead(head, tail, 1);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 3);
    insertAtHead(head, tail, 4);
    insertAtHead(head, tail, 5);
    insertAtHead(head, tail, 6);
    insertAtHead(head, tail, 7);
    insertAtHead(head, tail, 8);
    insertAtHead(head, tail, 9);
    insertAtHead(head, tail, 10);

    cout << "\nOriginal List: ";
    print(head);
    cout << endl;

    head = reverseList(head);

    cout << "Reversed List: ";
    print(head);
    cout << endl;
    cout << endl;

    return 0;
}