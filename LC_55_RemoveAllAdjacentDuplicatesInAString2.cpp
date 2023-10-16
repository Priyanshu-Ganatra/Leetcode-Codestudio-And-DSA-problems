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

// two pointer method. O(n) time and O(n) space.
string methodTwo(string &s, int &k)
{
    int i = 0, j = 0;
    int n = s.length(); 
    vector<int> count(n); // count[i] will store the count of char at i in s
    while (j < n)
    {
        s[i] = s[j]; // copy char at j to i to remove duplicates in s in-place and i will point to the last char in s after removing duplicates
        count[i] = 1; // count[i] will store the count of char at i in s and we are initializing it to 1 because we have one char at i in s now
        if (i > 0 && s[i] == s[i - 1]) // this means we have one more char same as s[i - 1] in s 
        {
            count[i] += count[i - 1];
        }
        {
            count[i] += count[i - 1];
        }
        // if count[i] == k, we need to remove k chars from s and i should be decremented by k to point to the last char in s after removing k chars
        if (count[i] == k)
        {
            i -= k; // i is decremented by k to point to the last char in s after removing k chars
        }
        i++, j++; // increment i and j to point to next char in s
    }
    return s.substr(0, i); // this is because i is pointing to the last char in s after removing duplicates
}

string removeDuplicates(string s, int k)
{
    // return methodOne(s, k);
    return methodTwo(s, k);
}

int main()
{
    string s = "nnwssswwnvbnnnbbqhhbbbhmmmlllm";
    int k = 3;
    cout << removeDuplicates(s, k) << endl;
    return 0;
}