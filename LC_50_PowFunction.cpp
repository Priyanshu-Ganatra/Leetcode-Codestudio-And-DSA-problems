#include <bits/stdc++.h>
using namespace std;

// LeetCode-50: https://leetcode.com/problems/powx-n/
// fast exponentiation tc = O(logn), sc = O(1)
double myPow(double x, int n)
{
    if (n < 0)
    {
        x = 1 / x;
    }
    long pow = labs(n); // this is done to handle the case when n = INT_MIN which will overflow if we try to convert it to positive
    double ans = 1;
    while (pow) 
    {
        if (pow & 1) // this finally assigns the precomputed value of x to ans when pow becomes 1 after all the right shifts
        { 
            ans *= x; 
        }
        x *= x; // x = x^2
        pow >>= 1; // pow = pow / 2
    }
    return ans;
}

int main()
{
    double x;
    int n;
    cin >> x >> n;
    cout << myPow(x, n) << endl;
    return 0;
}