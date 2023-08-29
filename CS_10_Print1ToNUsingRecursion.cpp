// Backtracking solution to print 1 to N using recursion
#include <bits/stdc++.h>
using namespace std;

vector<int> printNos(int x) {
    // Base case: Stop recursion when x becomes 0
    if (x == 0) {
        return vector<int>(); // at the end of the recursion, we return an empty vector and then this gets filled up as the recursion goes back up to its previous calls, programming is truly magnificent, isn't it?
    }
    // Recursive call
    vector<int> ans = printNos(x - 1); // calling function before adding to vector will print in ascending order, because at the end of the recurive call the variable x would be 1, then we return to a function with x = 2, then x = 3, and so on
    // Add the current number to the vector
    ans.push_back(x);
    return ans;
}

int main()
{
    vector<int> ans = printNos(5);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    
    return 0;
}