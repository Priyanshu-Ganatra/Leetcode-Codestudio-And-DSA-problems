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
    long num = labs(n);
    double pow = 1;
    while (num)
    { // equivalent to while(num != 0)
        if (num & 1)
        { // equivalent to if((num & 1) != 0)
            pow *= x;
        }
        x *= x;
        num >>= 1;
    }
    return pow;
}

int main()
{
    double x;
    int n;
    cin >> x >> n;
    cout << myPow(x, n) << endl;
    return 0;
}