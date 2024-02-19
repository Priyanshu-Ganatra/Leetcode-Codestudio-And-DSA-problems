#include <bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int> pq; // max heap
    pq.push(10);
    pq.push(15);
    pq.push(5);
    pq.push(20);
    pq.push(30);

    cout << "Top element: " << pq.top() << endl;    
    pq.pop();
    cout << "Top element: " << pq.top() << endl;  
    if(pq.empty())
        cout << "Heap is empty" << endl;
    else
        cout << "Heap is not empty" << endl;
    return 0;
}
