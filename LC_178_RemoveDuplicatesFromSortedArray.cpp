#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        // fast and slow pointers, i is slow and j is fast
        // remember the array is sorted
        int n = arr.size();
	    int i = 0;
	    for(int j = 1; j < n; j++){
		// if we find an element not equal to previous unique element, we do the in-place change
		// of the newly found element one place after the previously found unique element 
		// and now the newly found unique element becomes the previously found unique element 
		// for further searching of another unique element if there exists one
		if(arr[i] != arr[j]){
			arr[i+1] = arr[j]; 
			i++;
		}
	}
	// In the end, the i pointer would be standing at a position where the last unique element
	// stands, and since the index starts with 0 and we want the no. of unique elements in the
	// array, we return (i+1)
	return (i+1); 
    }
};

int main() {
    Solution obj;
    vector<int> a = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    int ans = obj.removeDuplicates(a);
    cout << "The number of unique elements in the array are: " << ans << endl;
    cout << "The array after removing the duplicates is: ";
    for (int i = 0; i < ans; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}