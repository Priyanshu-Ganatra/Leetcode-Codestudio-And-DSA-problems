#include <bits/stdc++.h>
using namespace std;

class MyStack
{
public:
    queue<int> q;
    MyStack()
    {
    }

    void push(int x)
    {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        int pop = q.front();
        q.pop();
        return pop;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};

int main()
{
    MyStack *obj = new MyStack();
    obj->push(1);
    obj->push(2);
    cout << obj->top() << endl;
    cout << obj->pop() << endl;
    cout << obj->empty() << endl;
    return 0;
}