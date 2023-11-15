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

ListNode *reverse(ListNode *&head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    while (curr != NULL)
    {
        ListNode *newNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = newNode;
    }
    return prev;
}

void addOne(ListNode *&head)
{
    head = reverse(head);

    ListNode *temp = head;
    int carry = 1;

    while (temp != NULL && carry != 0)
    {
        int totalSum = temp->val + carry;
        int digit = totalSum % 10;
        carry = totalSum / 10;
        temp->val = digit;
        if (carry != 0 && temp->next == NULL)
        {
            ListNode *newNode = new ListNode(carry);
            temp->next = newNode;
            carry = 0;
        }
        temp = temp->next;
    }

    head = reverse(head);
}


int main()
{
    ListNode *head = NULL;
    ListNode *tail = NULL;

    insertAtHead(head, tail, 9);
    insertAtHead(head, tail, 9);
    insertAtHead(head, tail, 9);

    cout << "Before adding one: ";
    print(head);
    cout << endl;

    addOne(head);
    cout << "After adding one: ";
    print(head);
    cout << endl;

    return 0;
}