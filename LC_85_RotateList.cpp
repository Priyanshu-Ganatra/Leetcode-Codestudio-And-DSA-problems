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

int getLen(ListNode *head)
{
    int len = 0;
    ListNode *temp = head;
    while (temp)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

// tc : O(n) and sc : O(1)
ListNode *rotateRight(ListNode *head, int k)
{
    if(!head) return 0;
    int len = getLen(head);
    int actualRotations = k % len;
    if(actualRotations == 0) return head;
    int newLastNodePos = len - actualRotations - 1;
    ListNode* newLastNode = head;
    for(int i = 0; i < newLastNodePos; i++){
        newLastNode = newLastNode -> next;
    }

    ListNode *newHead = newLastNode -> next;
    newLastNode -> next = NULL;
    ListNode *temp = newHead;
    while(temp -> next){
        temp = temp -> next;
    }
    temp -> next = head;
    return newHead;
}

int main()
{
    ListNode *head = NULL;
    ListNode *tail = NULL;
    insertAtHead(head, tail, 5);
    insertAtHead(head, tail, 4);
    insertAtHead(head, tail, 3);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 1);
    cout << "Before Rotating : ";
    print(head);
    cout << endl;
    cout << "After Rotating by 2 : ";
    ListNode *newHead = rotateRight(head, 2);
    print(newHead);
    return 0;
}