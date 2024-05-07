//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    int solve(long long arr[], long long& n){
        priority_queue<int, vector<int>, greater<int> > minHeap;
        // insert all elems.
        for(int i = 0; i < n; i++){
            int val = arr[i];
            minHeap.push(val);
        }
        int cost = 0;
        while(minHeap.size() > 1){
            int a = minHeap.top();
            minHeap.pop();
            int b = minHeap.top();
            minHeap.pop();
            cost += a+b;
            minHeap.push(a+b);
        }
        return cost;
    }
    public:
    long long minCost(long long arr[], long long n) {
        int ans = solve(arr,n);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends