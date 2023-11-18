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
vector<int> nodesBetweenCriticalPoints(ListNode *head)
{
    vector<int> ans = {-1, -1};
    ListNode* prev = head;
    if(!prev) return ans;
    ListNode* curr = head -> next;
    if(!curr) return ans;
    ListNode* next = curr -> next;
    if(!next) return ans;

    int firstCP = -1, lastCP = -1;
    int minDist = INT_MAX;
    int i = 1;
    while (next)
    {
        bool isCP = ((curr -> val > prev->val && curr->val > next->val) || (curr->val < prev->val && curr->val < next->val)) ? true : false;
        if(isCP && firstCP == -1){
            firstCP = i;
            lastCP = i;
        }
        else if(isCP){
            minDist = min(minDist, i - lastCP);
            lastCP = i;
        }
        ++i;
        prev = curr;
        curr = next;
        next = next -> next;
    }
    
    if(lastCP == firstCP) return ans; // only 1 CP was found
    else{
        ans[0] = minDist;
        ans[1] = lastCP - firstCP;
    }
    return ans;
}

int main()
{
    ListNode *head = NULL;
    ListNode *tail = NULL;

    insertAtHead(head, tail, 7);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 3);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 3);
    insertAtHead(head, tail, 1);

    cout << "LL is: ";
    print(head);
    cout << endl;

    vector<int> ans = nodesBetweenCriticalPoints(head);
    cout << "Minimum dist. between CPs: " << ans[0] << "\nMaximum dist. between CPs: " << ans[1] << endl;
    return 0;
}