// Dutch national flag algorithm
// Space: constant
// Time: O(n), better, not optimal
#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sort012(int arr[], int n)
{
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
            mid++;
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    int arr[] = {0, 1, 2, 2, 1, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Array before sorting: "<<endl;
    printArray(arr, n);
    sort012(arr, n);
    cout<<"Array after sorting: "<<endl;
    printArray(arr, n);
    return 0;
}
