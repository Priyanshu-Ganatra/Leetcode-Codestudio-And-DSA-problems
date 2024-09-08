//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int n = arr.size();
        
        // approach 1 - Dutch national flag algo
        // int i = 0, j = n-1;
        // while(i < j){
        //     if(arr[i] == 0) i++;
        //     else if(arr[j] == 1) j--; // or this also works: if(arr[j] == 1) j--;
        //     else swap(arr[i], arr[j]);
        // }
        
        // approach 2 - fast and slow pointers, i = fast & j = slow
        int i = 0, j = 0;
        while(i < n){
            if(arr[i] == 0) {
                swap(arr[i], arr[j]);
                j++;
                i++;
            }
            else i++;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        ob.segregate0and1(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends