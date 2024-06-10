#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // int lowerBound(vector<int>& arr, int x) {
    //     int start = 0, end = arr.size() - 1;
    //     int ans = end;
    //     while (start <= end) {
    //         int mid = (start + end) / 2;
    //         if (arr[mid] >= x) {
    //             ans = mid;
    //             end = mid - 1;
    //         } else if (arr[mid] < x) {
    //             start = mid + 1;
    //         }
    //     }
    //     return ans;
    // }

    // tc: O(log(n-k)) & sc: O(1)
    vector<int> bsMethod(vector<int> &arr, int k, int x)
    {
        // lower bound
        // int h = lowerBound(arr, x);
        int h = distance(arr.begin(), lower_bound(arr.begin(), arr.end(), x));
        int l = h - 1;
        while (k--)
        {
            if (l < 0)
                h++; // edge case which prevents l to get out of bounds
            else if (h >= arr.size())
                l--; // edge case which prevents h to get out of bounds
            else if (x - arr[l] > arr[h] - x)
            {
                h++;
            }
            else
            {
                l--;
            }
        }
        return vector<int>(arr.begin() + l + 1, arr.begin() + h);
    }

    // vector<int> twoPointerMethod(vector<int>& arr, int k, int x) {
    //     int l = 0, h = arr.size()-1;
    //     while(h-l >= k){
    //         if(x - arr[l] > arr[h] - x){
    //             l++;
    //         }
    //         else{
    //             h--;
    //         }
    //     }
    //     return vector<int>(arr.begin() + l, arr.begin() + h + 1);
    // }

    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        // return twoPointerMethod(arr, k, x); // tc: O(n-k) & sc: O(1)
        return bsMethod(arr, k, x);
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4, x = 3;
    vector<int> res = sol.findClosestElements(arr, k, x);
    for (int i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}