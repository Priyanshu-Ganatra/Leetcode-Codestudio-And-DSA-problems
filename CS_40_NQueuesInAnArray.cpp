#include <bits/stdc++.h>
using namespace std;

class NQueue
{
public:
    int n, k, freeSpot; // n is size of main array, k is number of queues, freeSpot is index of free spot in main array
    int *arr, *front, *rear, *next;
    // constructor
    NQueue(int n, int s) : n(s), k(n), freeSpot(0)
    {
        arr = new int[n];
        next = new int[n];
        front = new int[k];
        rear = new int[k];

        // Initialize all queues as empty
        for (int i = 0; i < k; i++)
        {
            front[i] = rear[i] = -1;
        }
        // intialize all spaces as free
        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1; // -1 is used to indicate end of free list, setting last element of next[] as -1 as it itself is the last free spot
    }

    // destructor
    ~NQueue()
    {
        delete[] arr;
        delete[] front;
        delete[] rear;
        delete[] next;
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m)
    {
        // overflow check
        if (freeSpot == -1)
        {
            cout << "Queue overflow";
            cout << ". Can't enqueue " << x << " into queue " << m << endl;
            return false; // No free spot left in main array thus queue overflow
        }

        int i = freeSpot;   // 1. Store index of free spot
        freeSpot = next[i]; // 2. Update index of free spot to next free spot
        // if first element is being enqueued
        if (front[m - 1] == -1)
        {
            front[m - 1] = i; // 3. Update front of queue m to index of free spot, m-1 because m is 1-indexed
        }
        else    
        {
            // link the previous rear to the new rear (some elements may be in between which belong to other queues)
            next[rear[m - 1]] = i; // 3. Update next of rear of queue m to index of free spot, m-1 because m is 1-indexed
        }
        next[i] = -1;    // 4. Update next of free spot to -1 to indicate end of queue 
        rear[m - 1] = i; // 5. Update rear of queue m to index of free spot, m-1 because m is 1-indexed
        arr[i] = x;      // 6. Put data in free spot
        cout << "Enqueued " << x << " into queue " << m << endl;
        return true; // 7. Return true as data is enqueued into queue
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m)
    {
        // underflow check
        if (front[m - 1] == -1)
        {
            cout << "Queue underflow";
            cout << ". Can't dequeue from queue " << m << endl;
            return -1; // Queue is empty thus queue underflow
        }

        // find index of front element of queue m to pop it
        int i = front[m - 1];   // 1. Store index of front element of queue m
        front[m - 1] = next[i]; // 2. Update front
        // update free spots
        next[i] = freeSpot; // 3. Update next of popped element to index of free spot
        freeSpot = i;       // 4. Update index of free spot to index of popped element
        cout << "Dequeued " << arr[i] << " from queue " << m << endl;
        return arr[i]; // 5. Return popped element
    }
};

int main()
{
    int n = 3, size = 6;
    cout << "Number of queues: " << n << endl;
    cout << "Size of main array: " << size << endl << endl;
    NQueue q(n, size);
    q.enqueue(1, 1);
    q.enqueue(2, 1);
    q.enqueue(3, 2);
    q.enqueue(4, 2);
    q.enqueue(5, 3);
    q.enqueue(6, 3);
    return 0;
}