#include <bits/stdc++.h>
using namespace std;

int partitionArray(int input[], int start, int end)
{
    int pivot = input[start];
    int i = start;
    int j = end;
    while (i < j)
    {
        while (input[i] <= pivot && i <= end - 1)
        { // end-1 bcoz it makes sure that i doesn't go out of bounds of the array when incrementing
            i++;
        }
        while (input[j] > pivot && j >= start + 1)
        { // start+1 bcoz it makes sure that j doesn't go out of bounds of the array when decrementing
            j--;
        }
        if (i < j)
            swap(input[i], input[j]);
    }
    swap(input[j], input[start]);
    return j;
}

void quickSort(int input[], int start, int end)
{
    if (start < end) // base case, if start == end, then there is only one element in the array, so no need to sort
    {
        int pIndex = partitionArray(input, start, end);
        quickSort(input, start, pIndex - 1);
        quickSort(input, pIndex + 1, end);
    }
}

int main(){
    int input[] = {2, 6, 8, 5, 4, 3};
    cout << "Array before sorting: ";
    for (int i = 0; i < sizeof(input) / sizeof(input[0]); i++)
        cout << input[i] << " ";
    int n = sizeof(input) / sizeof(input[0]);
    quickSort(input, 0, n - 1);
    cout << "\nArray after sorting: ";
    for (int i = 0; i < n; i++)
        cout << input[i] << " ";
    return 0;
}