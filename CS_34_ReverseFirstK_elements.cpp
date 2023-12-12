#include <bits/stdc++.h>
using namespace std;

queue<int> reverseElements(queue<int> q, int k)
{
    stack<int> s;
    int n = q.size();
    // push first k element in stack
    for (int i = 0; i < k; i++)
    {
        s.push(q.front());
        q.pop();
    }

    // push all k elements in queue
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    // pop and push first n-k elements into queue again
    for (int i = 0; i < n - k; i++)
    {
        q.push(q.front());
        q.pop();
    }
    return q;
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    int k = 3;
    q = reverseElements(q, k);

    cout << "Queue after reversing first " << k << " elements: ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}