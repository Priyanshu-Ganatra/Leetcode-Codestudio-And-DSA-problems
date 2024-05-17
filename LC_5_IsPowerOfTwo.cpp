#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // tc : O(logn) sc : O(1)
    // bool isPowerOfTwo(int n)
    // {
    //     if (n == 0)
    //         return false;
    //     while (n % 2 == 0)
    //         n /= 2;
    //     return n == 1;
    // }

    // tc : O(logn) sc : O(1)
    // bool isPowerOfTwo(int n)
    // {
    //     int count = 0;
    //     while (n > 0)
    //     {
    //         int lastBit = n & 1;
    //         if (lastBit == 1)
    //             count++;
    //         n >>= 1;
    //     }

    //     return count == 1;
    // }

    // tc : O(1) sc : O(1)
    bool isPowerOfTwo(int n)
    {
        if (n == 0) 
            return false;
        return (n & (n - 1)) == 0;
    }

};

int main()
{
    Solution sol;
    cout << sol.isPowerOfTwo(1) << endl;
    cout << sol.isPowerOfTwo(16) << endl;
    cout << sol.isPowerOfTwo(218) << endl;
    return 0;
}