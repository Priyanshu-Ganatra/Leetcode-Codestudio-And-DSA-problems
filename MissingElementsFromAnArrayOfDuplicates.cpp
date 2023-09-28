#include <bits/stdc++.h>
using namespace std;

// void findMissingVisitingMethod(int *a, int n){ // tc: O(n), sc: O(1)
//     // visited method
//     for (int i = 0; i < n; i++)
//     {
//         int index = a[i];
//         if(a[index - 1] > 0){
//             a[index - 1] = -a[index - 1]; // mark visited
//         }
//     }
//     // after this loop, the array looks like this:
//     // -1 3 -5 -3 -4

//     // all (indexes + 1) with positive elements are missing numbers
//     for (int i = 0; i < n; i++)
//     {
//         if(a[i] > 0){
//             cout << i + 1 << " ";
//         }
//     }
    
// }

void findMissingSortingAndSwappingMethod(int *a, int n){ // tc: O(n), sc: O(1)
    int i = 0;
    while (i < n)
    {
        int index = a[i] - 1;
        if(a[i] != a[index]){
            swap(a[i], a[index]);
        }
        else{
            i++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] != i + 1)
        {
            cout << i + 1 << " ";
        }
        
    }
    cout << endl;   
}

int main(){
    int a[] = {1,3,5,3,4};
    int n = sizeof(a)/sizeof(a[0]);
    // findMissingVisitingMethod(a, n);
    findMissingSortingAndSwappingMethod(a, n);
}