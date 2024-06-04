//{ Driver Code Starts
// Initial Template for C++

// C program for implementation of Bubble sort
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

// swapping the elements
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(int v[], int n)
    {
        // Your code here
        for (int i = 0; i < n - 1; i++)
        {
            bool didSwap = false;
            for (int j = 0; j < n - i - 1; j++)
            {
                if (v[j] > v[j + 1])
                {
                    swap(v[j], v[j + 1]);
                    didSwap = true;
                }
            }
            if (!didSwap)
                break;
        }
    }
};

//{ Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000], n, T, i;

    scanf("%d", &T);

    while (T--)
    {

        scanf("%d", &n);

        for (i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        Solution ob;

        ob.bubbleSort(arr, n);
        printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends