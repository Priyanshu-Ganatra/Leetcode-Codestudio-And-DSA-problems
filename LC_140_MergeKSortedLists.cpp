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

class compare
{
public:
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    priority_queue<ListNode *, vector<ListNode *>, compare>
        pq;

    // process 1st elem of every list
    for (int i = 0; i < lists.size(); i++)
    {
        ListNode *listHead = lists[i];
        if (listHead)
            pq.push(listHead);
    }

    // for new LL
    ListNode *head = NULL;
    ListNode *tail = NULL;

    while (!pq.empty())
    {
        ListNode *topNode = pq.top();
        pq.pop();

        if (!head)
        {
            head = topNode;
            tail = topNode;
            if (tail->next != NULL)
                pq.push(tail->next);
        }
        else
        {
            tail->next = topNode;
            tail = topNode;
            if (tail->next)
                pq.push(tail->next);
        }
    }
    return head;
}

int main()
{
    vector<ListNode *> lists;
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    ListNode *l3 = new ListNode(2);
    l3->next = new ListNode(6);

    lists.push_back(l1);
    lists.push_back(l2);
    lists.push_back(l3);

    ListNode *result = mergeKLists(lists);

    while (result)
    {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}