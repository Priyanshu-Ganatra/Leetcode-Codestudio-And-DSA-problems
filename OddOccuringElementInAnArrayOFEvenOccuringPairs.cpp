#include <bits/stdc++.h>
using namespace std;

int findOddOccuringElement(int arr[], int n)
{
    int s = 0;
    int e = n - 1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (s==e)
        {
            return s;
        }

        if (mid % 2 == 0)
        {
            if (arr[mid] == arr[mid + 1])
            {
                // go right, mid + 2 as we have already checked mid + 1
                s = mid + 2;
            }
            else
            {
                // go left, e = mid and not mid - 1 as mid is a potential answer
                e = mid;
            }
        }
        else
        {
            if (arr[mid] == arr[mid - 1])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6};
    int n = 11;
    int idx = findOddOccuringElement(arr, n);

    if (idx != -1)
    {
        cout << "Odd occuring element is " << arr[idx] << endl;
    }
    else
    {
        cout << "No odd occuring element found" << endl;
    }
    return 0;
}