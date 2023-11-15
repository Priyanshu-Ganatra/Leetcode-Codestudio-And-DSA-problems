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

// using dummy node approach - O(n) time, O(1) space
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    
    ListNode *ans = new ListNode(-1); // dummy node
    ListNode *mptr = ans; // merge pointer
     
    while (l1 && l2) // while both lists are not empty
    {
        if (l1->val <= l2->val) // if l1's value is smaller
        {
            mptr->next = l1; // point merge pointer to l1
            mptr = l1; // move merge pointer to l1
            l1 = l1->next; // move l1 to next node
        }
        else // if l2's value is smaller
        {
            mptr->next = l2; // point merge pointer to l2
            mptr = l2; // move merge pointer to l2
            l2 = l2->next; // move l2 to next node
        }
    }
    if(l1) // if l1 is not empty but l2 is empty
    {
        mptr->next = l1; // point merge pointer to l1
    }
    if(l2) // if l2 is not empty but l1 is empty
    {
        mptr->next = l2; // point merge pointer to l2
    }
    return ans->next; // return the merged list
}

int main()
{
    ListNode *head1 = NULL;
    ListNode *tail1 = NULL;
    insertAtHead(head1, tail1, 4);
    insertAtHead(head1, tail1, 2);
    insertAtHead(head1, tail1, 1);
    insertAtHead(head1, tail1, 1);
    insertAtHead(head1, tail1, 1);
    cout << "List 1: ";
    print(head1);
    cout << endl;

    ListNode *head2 = NULL;
    ListNode *tail2 = NULL;
    insertAtHead(head2, tail2, 4);
    insertAtHead(head2, tail2, 3);
    insertAtHead(head2, tail2, 1);
    cout << "List 2: "; 
    print(head2);
    cout << endl;

    ListNode *head3 = mergeTwoLists(head1, head2);
    cout << "Merged List: ";
    print(head3);
    cout << endl;

    return 0;
}