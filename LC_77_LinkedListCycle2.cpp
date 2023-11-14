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

// Floyd's Cycle Detection Algorithm (Tortoise and Hare Algorithm) - tc: O(n), sc: O(1)
ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        // check for loop
        if (fast == slow)
        {
            break;
        }
    }

    // if no loop th
    if(fast == NULL)
    {
        return NULL;
    }

    // here the pointers meet
    slow = head;

    // move slow and fast -> 1 step
    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }

    // return starting point
    return slow;
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