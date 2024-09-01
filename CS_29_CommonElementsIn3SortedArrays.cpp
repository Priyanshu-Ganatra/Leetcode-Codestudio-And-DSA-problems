//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find common elements in three arrays.
    // tc: O(n1 + n2 + n3) and sc: O(1) because we are not using any extra space except the answer vector
    vector<int> commonElements(vector<int> &A, vector<int> &B,
                               vector<int> &C) {
        //code here.
        int i=0,j=0,k=0;
        int n1=A.size(),n2=B.size(),n3=C.size();
        vector<int> ans;
        int last = 0;
        while(i<n1 && j<n2 && k<n3){
            if(A[i] == B[j] && B[j] == C[k] && A[i] != last){
                ans.push_back(A[i]);
                last = A[i];
                i++; j++; k++;
            }
            else if(min({A[i], B[j], C[k]}) == A[i]) i++;
            else if(min({A[i], B[j], C[k]}) == B[j]) j++;
            else k++;
        }
        return ans;

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr, crr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        string input3;
        getline(cin, input3);
        stringstream ss3(input3);
        int number3;
        while (ss3 >> number3) {
            crr.push_back(number3);
        }
        Solution ob;
        vector<int> res = ob.commonElements(arr, brr, crr);
        if (res.size() == 0)
            cout << -1;
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
}
// } Driver Code Ends