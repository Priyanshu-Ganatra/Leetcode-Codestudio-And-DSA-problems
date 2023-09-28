#include <bits/stdc++.h>
using namespace std;

int findOddOccuringElement(int arr[], int n)
{
    int s = 0, e = n -1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        // single element
        if (s == e)
            return arr[s];

        // checking mid - even or odd
        if (mid & 1){ // odd
            if (mid-1 >= 0 && arr[mid-1] == arr[mid])
            {
                s = mid + 1; // go right
            }
            else{
                e = mid - 1; // go left
            }
        }
        else{ // even
            if (mid+1 < n && arr[mid] == arr[mid+1]) // we are at the left part
            {
                s = mid + 2; // go right
            }
            else{
                // either we are at the right part or on the answer that's why e = mid 
                // bcoz e = mid - 1 might lose the answer
                e = mid; // go left
            }
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 1, 2, 2, 3, 3, 4, 50, 50, 65, 65};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findOddOccuringElement(arr, n);
    return 0;
}