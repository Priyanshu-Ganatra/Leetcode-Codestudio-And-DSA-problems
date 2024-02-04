#include <bits/stdc++.h>
using namespace std;

// Max Heap
class MaxHeap
{
public:
    int *arr;
    int size;
    int capacity;

    MaxHeap(int capacity)
    {
        this->arr = new int[capacity];
        this->capacity = capacity;
        this->size = 0;
    }

    // O(logn)
    void insert(int val)
    {
        if (size == capacity)
        {
            cout << "Heap is full" << endl;
            return;
        }
        // size increase and insert at last
        size++;
        int index = size;
        arr[index] = val;

        // take the value to its correct position i.e. heapify
        while (index > 1)
        {
            int parentIndex = index / 2;
            if (arr[parentIndex] < arr[index])
            {
                swap(arr[parentIndex], arr[index]);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    // O(logn)
    int deleteNode()
    {
        int ans = arr[1];
        // replacement
        arr[1] = arr[size];
        // delete last element from its original position
        size--;
        // heapify
        int index = 1;
        while (index < size) // not checking last element because it has no children
        {
            int leftIndex = 2 * index;
            int rightIndex = 2 * index + 1;
            // find max of left and right child
            int maxIndex = index;
            // check if left child exists and is greater than parent
            if (leftIndex <= size && arr[leftIndex] > arr[maxIndex])
            {
                maxIndex = leftIndex;
            }
            // check if right child exists and is greater than parent and left child
            if (rightIndex <= size && arr[rightIndex] > arr[maxIndex])
            {
                maxIndex = rightIndex;
            }

            // if no change i.e. parent is greater than both children, which means heap property is satisfied
            if (maxIndex == index)
            {
                break;
            }
            // swap parent with max child
            swap(arr[maxIndex], arr[index]);
            index = maxIndex; // update index to max child because we need to heapify from there
        }
        return ans;
    }

    // O(n) - this method corrects the heap property of the array
    void heapify(vector<int> &arr, int n, int index){
        int leftIndex = 2 * index;
        int rightIndex = 2 * index + 1;
        int maxIndex = index;

        // check if left child exists and is greater than parent
        if (leftIndex <= n && arr[leftIndex] > arr[maxIndex])
        {
            maxIndex = leftIndex;
        }
        // check if right child exists and is greater than parent and left child
        if (rightIndex <= n && arr[rightIndex] > arr[maxIndex])
        {
            maxIndex = rightIndex;
        }

        // if maxIndex is not same as index, then swap and heapify
        if (maxIndex != index)
        {
            swap(arr[maxIndex], arr[index]);
            index = maxIndex; // update index to max child because we need to heapify from there
            heapify(arr, n, index);
        }
    }
};

int main()
{
    MaxHeap h(10);
    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.insert(40);

    cout << "Printing heap before deletion:" << endl;
    for (int i = 1; i <= h.size; i++)
    {
        cout << h.arr[i] << " ";
    }
    int deletedElem = h.deleteNode();
    cout << endl << "Deleting element: " << deletedElem << endl;
    cout << "Printing heap after deletion:" << endl;
    for (int i = 1; i <= h.size; i++)
    {
        cout << h.arr[i] << " ";
    }
    cout << endl;
    cout << "Heapify this incorrect heap:" << endl;
    vector<int> v = {0, 45, 50, 60, 40, 30, 20};
    for (int i = 1; i <= 6; i++)
    {
        cout << v[i] << " ";
    }
    h.heapify(v, 4, 1);
    cout << endl << "Printing array after heapify:" << endl;
    for (int i = 1; i <= 6; i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}