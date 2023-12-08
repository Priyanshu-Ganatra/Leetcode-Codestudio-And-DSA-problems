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

// tc: O(n), sc: O(n)
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *ans = new ListNode(-1);
    ListNode *it = ans;
    int carry = 0;
    while(l1 || l2 || carry){ // if any of the LLs is not NULL or carry is not 0
        int a = l1 ? l1->val : 0; // if l1 is not NULL, then a = l1->val, else a = 0
        int b = l2 ? l2->val : 0; // if l2 is not NULL, then b = l2->val, else b = 0
        int sum = a + b + carry;
        int digit = sum % 10; 
        carry = sum/10;
        it->next = new ListNode(digit);  // create a new node with digit as value
        l1 = l1 ? l1->next : NULL; // if l1 is not NULL, then l1 = l1->next, else l1 = NULL
        l2 = l2 ? l2->next : NULL; // if l2 is not NULL, then l2 = l2->next, else l2 = NULL
        it = it->next; // move the iterator to the next node
    }
    ListNode *finalAns = ans->next; // finalAns is the LL starting from the next node of ans
    delete ans; // delete the dummy node
    return finalAns; // return the finalAns
}

int main()
{
    ListNode *head1 = NULL;
    ListNode *tail1 = NULL;
    insertAtHead(head1, tail1, 3);
    insertAtHead(head1, tail1, 4);
    insertAtHead(head1, tail1, 2);
    cout << "LL1: ";
    print(head1);
    cout << endl;

    ListNode *head2 = NULL;
    ListNode *tail2 = NULL;
    insertAtHead(head2, tail2, 4);
    insertAtHead(head2, tail2, 6);
    insertAtHead(head2, tail2, 5);
    cout << "LL2: ";
    print(head2);
    cout << endl;

    ListNode *head3 = addTwoNumbers(head1, head2);
    cout << "LL3: ";
    print(head3);
    cout << endl;

    return 0;
}