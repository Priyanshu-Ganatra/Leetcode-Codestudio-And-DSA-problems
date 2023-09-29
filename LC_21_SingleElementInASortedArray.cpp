#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int> &arr)
{
    int n = arr.size();
    int s = 0, e = n - 1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        // single element
        if (s == e)
            return arr[s];

        // checking mid - even or odd
        if (mid & 1)
        {                                                 // odd
            if (mid - 1 >= 0 && arr[mid - 1] == arr[mid]) // we are at the left part
            {
                s = mid + 1; // go right
            }
            else
            {
                e = mid - 1; // go left
            }
        }
        else
        {                                                // even
            if (mid + 1 < n && arr[mid] == arr[mid + 1]) // we are at the left part
            {
                s = mid + 2; // go right, mid + 2 bcoz mid + 1 is the already checked element
            }
            else
            {
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
    vector<int> arr = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << "The single element in the array is: " << singleNonDuplicate(arr);
    return 0;
}