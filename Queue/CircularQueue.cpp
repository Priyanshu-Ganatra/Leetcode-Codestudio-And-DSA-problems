#include <bits/stdc++.h>
using namespace std;

class CQueue
{
public:
    int* arr;
    int size, front, rear;

    CQueue(int size)
    {
        this->size = size;   
        arr = new int[size]{0};
        front = rear = -1;
    }

    void push(int val){
        // overflow
        if((front == 0 && rear == size-1) || (rear == front-1)){
            cout << "Overflow!" << " Can't push " << val << endl;
            return;
        }
        // empty case -> first element
        else if(front == -1 && rear == -1){
            front++;
            rear++;
            arr[rear] = val;
        }
        // circular nature
        else if(rear == size-1 && front != 0){
            rear = 0;
            arr[rear] = val;
        }
        // normal case
        else{
            rear++;
            arr[rear] = val;
        }
    }

    void pop(){
        // underflow 
        if(front == -1 && rear == -1){
            cout << "Underflow" << endl;
            return;
        }
        // single element
        else if(front == rear){
            cout << "Popped: " << arr[front] << endl;
            arr[front] = -1;
            front = rear = -1;
        }
        // circular nature
        else if(front == size-1){
            cout << "Popped: " << arr[front] << endl;
            arr[front] = -1;
            front = 0;
        }
        // normal case
        else{
            cout << "Popped: " << arr[front] << endl;
            arr[front] = -1;
            front++;
        }
    }

    void print(){
        cout << "-----------------" << endl;
        cout << "Front: " << front << " Rear: " << rear << endl;
        cout << "Printing Queue: ";
        for(int i=0; i<size; i++){
            cout << arr[i] << " ";
        }
        cout << endl << "-----------------" << endl;
        cout << endl;
    }
};

int main()
{
    CQueue q(5);
    q.print();
    q.push(10);
    q.print();
    q.push(20);
    q.print();
    q.push(30);
    q.print();
    q.push(40);
    q.print();
    q.push(50);
    q.print();
    q.push(60);
    q.pop();
    q.pop();
    q.pop();
    q.print();
    q.push(100);
    q.print();
    q.push(200);
    q.print();
    q.push(300);
    q.print();
    q.push(400);
}