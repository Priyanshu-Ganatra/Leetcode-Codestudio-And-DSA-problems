#include <bits/stdc++.h>
using namespace std;

class NStack
{
    int *arr;
    int *top;
    int *next;    // To store next entry in all stacks (the index of below the top element in the main array of stack m - useful for pop operation) and free list
    int n;        // Number of stacks
    int size;     // Size of main array
    int freeSpot; // Index of free spot in main array
public:
    // constructor
    NStack(int N, int S) : n(N), size(S)
    {
        freeSpot = 0;         // Initially all spaces are free
        arr = new int[size];  // Main array of size S
        top = new int[n];     // Stores top element of each stack in the main array thus same size as number of stacks
        next = new int[size]; // Stores next entry in all stacks and free list thus same size as main array

        // Initialize all stacks as empty
        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }

        // Initialize all spaces as free
        for (int i = 0; i < size - 1; i++)
        {
            next[i] = i + 1;
        }
        next[size - 1] = -1; // -1 is used to indicate end of free list, setting last element of next[] as -1 as it itself is the last free spot
    }

    // destructor
    ~NStack()
    {
        delete[] arr;
        delete[] top;
        delete[] next;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    // tc: O(1) sc: O(1)
    bool push(int x, int m)
    {
        if (freeSpot == -1)
        {
            cout << "Stack overflow";
            cout << ". Can't push " << x << " into stack " << m << endl;
            return false; // No free spot left in main array thus stack overflow
        }

        int i = freeSpot;     // 1. Store index of free spot
        freeSpot = next[i];   // 2. Update index of free spot to next free spot
        arr[i] = x;           // 3. Put data in free spot
        next[i] = top[m - 1]; // 4. Update next of free spot to index of top element of stack m, m-1 because m is 1-indexed
        top[m - 1] = i;       // 5. Update top of stack m to index of free spot, m-1 because m is 1-indexed
        cout << "Pushed " << x << " into stack " << m << endl;
        return true; // 6. Return true as data is pushed into stack
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    // tc: O(1) sc: O(1)
    int pop(int m)
    {
        if (top[m - 1] == -1)
        {
            cout << "Stack underflow";
            cout << ". Can't pop from stack " << m << endl;
            return -1; // Stack is empty thus stack underflow
        }

        // reverse process of push
        int i = top[m - 1];   // 1. Store index of top element of stack m
        top[m - 1] = next[i]; // 2. Update top of stack m to index of next element of top element of stack m (the element below the top element in the main array of stack m)
        int popped = arr[i];  // 3. Store popped element
        next[i] = freeSpot;   // 4. Update next of popped element to index of free spot
        freeSpot = i;         // 5. Update index of free spot to index of popped element
        cout << "Popped " << popped << " from stack " << m << endl;
        return popped; // 6. Return popped element
    }
};

int main()
{
    int n = 3, size = 6;
    cout << "Number of stacks: " << n << endl;
    cout << "Size of main array: " << size << endl << endl;
    NStack stack(n, size);
    stack.push(100, 1);
    stack.push(200, 1);
    stack.push(2000, 2);
    stack.push(8, 3);
    stack.push(4, 3);
    stack.push(2, 3);
    stack.push(3000, 2);
    stack.push(1, 3);
}