#include <bits/stdc++.h>
using namespace std;

// arr : given array
// l : starting index of the array i.e 0
// r : ending index of the array i.e size-1
// k : find kth smallest element and return using this function
int kthSmallest(int arr[], int l, int r, int k)
{
    priority_queue<int> pq;
    // process 1st k elements
    for (int i = 0; i < k; i++)
    {
        int elem = arr[i];
        pq.push(elem);
    }

    for (int i = k; i <= r; i++)
    {
        int elem = arr[i];
        if (elem < pq.top())
        {
            pq.pop();
            pq.push(elem);
        }
    }
    return pq.top();
}

int main()
{
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    cout << kthSmallest(arr, 0, n - 1, k) << endl;
    return 0;
}