#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
public:
    stack<int> s1, s2;
    MyQueue()
    {
    }

    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        int pop = -1;
        if (!s2.empty())
        {
            pop = s2.top();
        }
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            pop = s2.top();
        }
        s2.pop();
        return pop;
    }

    int peek()
    {
        int peek = -1; // front element
        if (!s2.empty())
        {
            peek = s2.top();
        }
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            peek = s2.top();
        }
        return peek;
    }

    bool empty()
    {
        return s1.empty() && s2.empty();
    }
};

int main()
{
    MyQueue *obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    int param_2 = obj->pop();
    int param_3 = obj->peek();
    bool param_4 = obj->empty();
    cout << param_2 << endl;
    cout << param_3 << endl;
    cout << param_4 << endl;
    return 0;
}