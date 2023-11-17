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

// tc - O(n), sc - O(1)
ListNode *mergeNodes(ListNode *head)
{
    if (head == NULL)
        return 0;
    ListNode *slow = head;
    ListNode *fast = head->next, *newLastNode = 0;
    int sum = 0;
    while (fast)
    {
        // if fast -> val != 0, then add it to sum
        if (fast->val != 0)
        {
            sum += fast->val; 
        }
        else
        {
            // here fast -> val = 0
            slow->val = sum;    // update the slow node's value with sum
            newLastNode = slow; // update the newLastNode
            slow = slow->next;  // move slow to next node
            sum = 0;            // reset sum
        }
        fast = fast->next; // move fast to next node
    }
    ListNode *temp = slow; // store the remaining nodes
    newLastNode->next = NULL;           // isolate the last node from the remaining nodes

    // delete the remaining nodes
    while (temp)
    {
        ListNode *temp2 = temp;
        temp = temp->next;
        delete temp2;
    }
    return head; // return the head
}

int main()
{
    ListNode *head1 = NULL;
    ListNode *tail1 = NULL;
    insertAtHead(head1, tail1, 0);
    insertAtHead(head1, tail1, 2);
    insertAtHead(head1, tail1, 5);
    insertAtHead(head1, tail1, 4);
    insertAtHead(head1, tail1, 0);
    insertAtHead(head1, tail1, 1);
    insertAtHead(head1, tail1, 3);
    insertAtHead(head1, tail1, 0);
    print(head1);

    return 0;
}