#include <bits/stdc++.h>
using namespace std;

// tc: O(n) sc: O(n) - iterative
// void reverseQueue(queue<int> &q){
    // stack<int> s;
    // while(!q.empty()){
    //     s.push(q.front());
    //     q.pop();
    // }
    // while(!s.empty()){
    //     q.push(s.top());
    //     s.pop();
    // }
// } 

// tc: O(n) sc: O(n) - recursive
void reverseQueue(queue<int> &q){
    if(q.empty()) return; // base case
    int x = q.front();
    q.pop();
    reverseQueue(q);
    q.push(x);
}

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    reverseQueue(q);
    cout << "Queue after reversing: ";
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
