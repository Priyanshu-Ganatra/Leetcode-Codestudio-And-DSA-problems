#include <bits/stdc++.h>
using namespace std;

void rightRotateByOne(int arr[], int n){
    int lastVal = arr[n-1];
    for(int i = n-1; i>0; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = lastVal;
}

void leftRotateByOne(int arr[], int n){
    int firstVal = arr[0];
    for(int i = 0; i<n-1; i++){
        arr[i] = arr[i+1];
    }
    arr[n-1] = firstVal;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(int);
    rightRotateByOne(arr, n);
    for(auto it: arr){
        cout << it << " ";
    }
    cout << endl;
    leftRotateByOne(arr, n);
    for(auto it: arr){
        cout << it << " ";
    }
    return 0;
}
