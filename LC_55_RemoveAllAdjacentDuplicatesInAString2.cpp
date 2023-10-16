#include <bits/stdc++.h>
using namespace std;

// this function checks if last k - 1 chars in ans are same as newCh or not
// bool areLastCharsSame(string &ans, char &newCh, int kMinus1)
// {
//     int it = ans.size() - 1;          // iterator to iterate over last k - 1 chars in ans
//     for (int i = 0; i < kMinus1; i++) // iterate over last k - 1 chars in ans
//     {
//         if (newCh != ans[it]) // if newCh is not same as any of the last k - 1 chars in ans, return false
//             return false;
//         it--; // decrement iterator to iterate over next char in ans
//     }
//     return true; // if newCh is same as all the last k - 1 chars in ans, return true
// }

// Pre-check characters method. O(n*(k-1)) time and O(n) space.
// string methodOne(string s, int k)
// {
//     string ans;
//     for (int i = 0; i < s.size(); i++)
//     {
//         char newCh = s[i];
//         if (ans.size() < k - 1) // k - 1 because we are checking for k - 1 chars in areLastCharsSame() function below and we are pushing newCh in ans after that
//         {
//             ans.push_back(newCh); // push newCh in ans if ans.size() < k - 1
//         }
//         else
//         {
//             // check if last k - 1 chars in ans are same as newCh or not and if they are same, pop them out
//             if (areLastCharsSame(ans, newCh, k - 1))
//             {
//                 // pop last k - 1 chars from ans
//                 for (int j = 0; j < k - 1; j++)
//                 {
//                     ans.pop_back();
//                 }
//             }
//             else // if last k - 1 chars in ans are not same as newCh, push newCh in ans
//                 ans.push_back(newCh);
//         }
//     }
//     return ans;
// }

// two pointer method. O(n) time and O(1) space.

string removeDuplicates(string s, int k)
{
    // return methodOne(s, k);
}

int main()
{
    string s = "nnwssswwnvbnnnbbqhhbbbhmmmlllm";
    int k = 3;
    cout << removeDuplicates(s, k) << endl;
    return 0;
}