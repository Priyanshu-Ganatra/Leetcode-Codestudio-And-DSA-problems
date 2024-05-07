//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        vector<int> valWtRatio;
        for(int i = 0; i<n; i++){
            float ratio = (arr[i].value*1.0)/arr[i].weight;
            valWtRatio.push_back(ratio);
        }
        priority_queue<pair<float, pair<int, int>>> maxHeap;
        for(int i = 0; i<n; i++){
            maxHeap.push({valWtRatio[i], {arr[i].value, arr[i].weight}});
        }
        // max heap is ready
        int ans = 0;
        while(w != 0 || !maxHeap.empty()){
            auto front = maxHeap.top();
            maxHeap.pop();
            float ratio = front.first;
            int value = front.second.first;
            int weight = front.second.second;
            // full insertion
            if (w >= weight){
                ans += value;
                w -= weight;
            }
            // fractional insertion
            else{
                // here w will be the remaining capacity of the knapsack
                ans += (ratio*w);
                w = 0;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--) {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends