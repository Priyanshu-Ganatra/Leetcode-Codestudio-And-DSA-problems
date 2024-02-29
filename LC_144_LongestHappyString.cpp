#include <bits/stdc++.h>
using namespace std;

class Info
{
public:
    char val;
    int count;
    Info(char ch, int cnt)
    {
        val = ch;
        count = cnt;
    }
};

class compare
{
public:
    bool operator()(Info *a, Info *b)
    {
        return a->count < b->count;
    }
};

string longestDiverseString(int a, int b, int c)
{
    priority_queue<Info *, vector<Info *>, compare> maxHeap;
    if (a > 0)
    {
        Info *temp = new Info('a', a);
        maxHeap.push(temp);
    }
    if (b > 0)
    {
        Info *temp = new Info('b', b);
        maxHeap.push(temp);
    }
    if (c > 0)
    {
        Info *temp = new Info('c', c);
        maxHeap.push(temp);
    }

    string ans = "";
    while (maxHeap.size() > 1)
    {
        Info *first = maxHeap.top();
        maxHeap.pop();
        Info *second = maxHeap.top();
        maxHeap.pop();

        if (first->count >= 2)
        {
            ans.push_back(first->val);
            ans.push_back(first->val);
            first->count -= 2;
        }
        else
        {
            ans.push_back(first->val);
            first->count -= 1;
        }

        if (second->count >= 2 && second->count >= first->count)
        {
            ans.push_back(second->val);
            ans.push_back(second->val);
            second->count -= 2;
        }
        else
        {
            ans.push_back(second->val);
            second->count -= 1;
        }

        if (first->count > 0)
        {
            maxHeap.push(first);
        }
        if (second->count > 0)
        {
            maxHeap.push(second);
        }
    }

    if (maxHeap.size() == 1)
    {
        Info *first = maxHeap.top();
        maxHeap.pop();

        if (first->count >= 2)
        {
            ans.push_back(first->val);
            ans.push_back(first->val);
            first->count -= 2;
        }
        else
        {
            ans.push_back(first->val);
            first->count -= 1;
        }
    }
    return ans;
}

int main()
{
    cout << longestDiverseString(1, 1, 7) << endl;
    cout << longestDiverseString(2, 2, 1) << endl;
    cout << longestDiverseString(7, 1, 0) << endl;
    return 0;
}   