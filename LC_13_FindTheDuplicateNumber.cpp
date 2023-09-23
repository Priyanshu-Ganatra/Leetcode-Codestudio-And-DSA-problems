#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &arr)
{
    // Brute
    // sort(arr.begin(), arr.end());
    // for(int i = 0; i<arr.size();i++){
    //     if(arr[i] == arr[i+1]){
    //         return arr[i];
    //     }
    // }
    // return -1;

    // -ve marking method
    // int ans = -1;
    // for(int i = 0; i<arr.size(); i++){
    //     int idx = abs(arr[i]);

    //     // already visited?
    //     if(arr[idx]<0){
    //         ans = idx;
    //         return ans;
    //     }

    //     // marking visited
    //     arr[idx] *= -1;
    // }
    // return ans;

    // positioning method
    while (arr[0] != arr[arr[0]])
    {
        swap(arr[0], arr[arr[0]]);
    }
    return arr[0];
}

int main()
{
    cout << "Array: ";
    vector<int> arr = {1, 3, 4, 2, 2};
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << "Duplicate number: ";
    cout << findDuplicate(arr);
    return 0;
}