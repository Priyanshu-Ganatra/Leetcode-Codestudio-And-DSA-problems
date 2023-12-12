#include <bits/stdc++.h>
using namespace std;

void interLeaveQueue(queue<int> &first)
{
    queue<int> second;
    // push 1st half of first queue in 2nd queue
    int size = first.size();
    for (int i = 0; i < size / 2; i++)
    {
        second.push(first.front());
        first.pop();
    }

    // merge both halves into the og queue named as first
    for (int i = 0; i < size / 2; i++)
    { 
        first.push(second.front());
        second.pop();

        first.push(first.front());
        first.pop();
    }
}

int main()
{
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);

    interLeaveQueue(q);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}