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

void removeCycle(ListNode *head)
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

    // if no loop then return from here
    if(fast == NULL)
    {
        return;
    }

    // here the pointers meet
    slow = head;

    // move slow and fast -> 1 step
    while (fast->next != slow->next)
    {
        fast = fast->next;
        slow = slow->next;
    }

    // remove cycle
    fast->next = NULL;
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

    removeCycle(head);

    cout << "Linked List after removing cycle:" << endl; 
    print(head);

    return 0;
}