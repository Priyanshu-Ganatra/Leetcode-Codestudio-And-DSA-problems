#include <bits/stdc++.h>
using namespace std;

class MyCircularDeque
{
    int size, front, rear, *arr;

public:
    MyCircularDeque(int k)
    {
        size = k;
        front = rear = -1;
        arr = new int[size];
    }

    ~MyCircularDeque()
    {
        delete[] arr;
    }

    bool insertFront(int value)
    {
        if (isFull())
            return false;
        else if (isEmpty())
        {
            front++;
            rear++;
            arr[front] = value;
        }
        else if (front == 0 && rear != size - 1)
        { // circular nature
            front = size - 1;
            arr[front] = value;
        }
        else
        {
            front--;
            arr[front] = value;
        }
        return true;
    }

    bool insertLast(int value)
    {
        if (isFull())
            return false;
        else if (isEmpty())
        {
            front++;
            rear++;
            arr[rear] = value;
        }
        else if (rear == size - 1 && front != 0)
        { // circular nature
            rear = 0;
            arr[rear] = value;
        }
        else
        {
            arr[++rear] = value;
        }
        return true;
    }

    bool deleteFront()
    {
        if (isEmpty())
            return false;
        else if (front == rear)
        { // single element
            arr[front] = -1;
            front = rear = -1;
        }
        else if (front == size - 1)
        { // circular nature
            arr[front] = -1;
            front = 0;
        }
        else
        {
            arr[front] = -1;
            front++;
        }
        return true;
    }

    bool deleteLast()
    {
        if (isEmpty())
            return false;
        else if (front == rear)
        { // single element
            arr[rear] = -1;
            front = rear = -1;
        }
        else if (rear == 0)
        { // circular nature
            rear = size - 1;
        }
        else
        {
            arr[rear] = -1;
            rear--;
        }
        return true;
    }

    int getFront()
    {
        if (isEmpty())
            return -1;
        else
        {
            return arr[front];
        }
    }

    int getRear()
    {
        if (isEmpty())
            return -1;
        else
        {
            return arr[rear];
        }
    }

    bool isEmpty()
    {
        return (front == -1 && rear == -1);
    }

    bool isFull()
    {
        return (front == 0 && rear == size - 1) || (rear == front - 1);
    }
};

int main()
{
    MyCircularDeque *obj = new MyCircularDeque(3);
    cout << obj->insertFront(1) << endl;
    cout << obj->insertLast(2) << endl;
    cout << obj->insertFront(3) << endl;
    cout << obj->insertLast(4) << endl;
    cout << obj->getRear() << endl;
    cout << obj->isFull() << endl;
    cout << obj->deleteLast() << endl;
    cout << obj->insertFront(4) << endl;
    cout << obj->getFront() << endl;
    return 0;
}
