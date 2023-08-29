#include <bits/stdc++.h>
using namespace std;

// Normal solution to print N to 1 using recursion
void doTheMagic(int x, vector<int> &ans) {
  if (x == 0) {
    return;
  }

  ans.push_back(x);
  doTheMagic(x - 1, ans);
}

vector<int> printNos(int x) {
  vector<int> ans;
  doTheMagic(x, ans);
  return ans;
}

// Backtracking solution to print N to 1 using recursion
// vector<int> printNos(int x, int n) {
//     // Base case: Stop recursion when x becomes 0
//     if (x > n) {
//         return vector<int>();
//     }
//     // Recursive call
//     vector<int> ans = printNos(x + 1, n); // calling function before adding to vector will print in reverse order, because at the end of the recurive call the variable x would be 5, then we return to a function with x = 4, then x = 3, and so on
//     // Add the current number to the vector
//     ans.push_back(x);
//     return ans;
// }

int main()
{
    // vector<int> ans = printNos(1, 5); // backtracking solution, here we need the 2nd parameter because we are adding  1 to x, so we need to know when to stop unlike the 1-N problem where we are subtracting 1 from x, so we can stop when x becomes 0
    vector<int> ans = printNos(5); // normal solution
    for (auto i : ans)
    {
        cout << i << " ";
    }
    
    return 0;
}