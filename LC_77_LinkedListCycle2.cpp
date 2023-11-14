#include <bits/stdc++.h>
using namespace std;

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

ListNode *detectCycle(ListNode *head)
{
    // Initialize two pointers, slow and fast, to the head of the linked list.
    ListNode *slow = head;
    ListNode *fast = head;

    // Move the slow pointer one step and the fast pointer two steps at a time
    // through the linked list,
    // until they either meet or the fast pointer reaches the end of the list.
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            // If the pointers meet, there is a cycle in the linked list.
            // Reset the slow pointer to the head of the linked list, and move both
            // pointers one step at a time
            // until they meet again. The node where they meet is the starting point
            // of the cycle.
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }

    // If the fast pointer reaches the end of the list without meeting the slow
    // pointer, there is no cycle in the linked list. Return nullptr.
    return nullptr;
}

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

    // create a loop
    tail->next = head->next->next->next->next;

    ListNode *ans = detectCycle(head);
    cout << "Starting point of the loop: ";
    cout << ans->val << endl;

    return 0;
}