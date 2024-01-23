#include <bits/stdc++.h>
using namespace std;

// tc: O(√n^n) sc: O(n)
int solve(int n)
{
    // base cases
    if (n == 0)
        return 0;

    int ans = INT_MAX;
    int i = 1;
    int end = sqrt(n);
    while (i <= end)
    {
        int perfectSquare = i * i;
        int numOfPerfectSquares = 1 + solve(n - perfectSquare);
        if (numOfPerfectSquares < ans)
        {
            ans = numOfPerfectSquares;
        }
        i++;
    }
    return ans;
}

int numSquares(int n)
{
    return solve(n);
}

int main()
{
    int n = 12;
    cout << "Minimum number of perfect squares that sum up to " << n << " is: ";
    cout << numSquares(n) << endl;
    return 0;
}